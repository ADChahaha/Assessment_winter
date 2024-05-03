import torch
import torch.nn as nn
import torch.optim as optim
import torchvision
from torch.utils.data import DataLoader
import pandas


class Net(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv1 = nn.Conv2d(1, 32, kernel_size=3, padding=1)
        self.act1 = nn.PReLU()
        self.pool1 = nn.MaxPool2d(2)
        self.conv2 = nn.Conv2d(32, 16, kernel_size=3, padding=1)
        self.act2 = nn.PReLU()
        self.pool2 = nn.MaxPool2d(2)
        self.func1 = nn.Linear(7 * 7 * 16, 32)
        self.act3 = nn.PReLU()
        self.func2 = nn.Linear(32, 16)
        self.act4 = nn.PReLU()
        self.func3 = nn.Linear(16, 10)
        torch.nn.init.normal_(self.func1.weight, mean=0, std=1.0)
        torch.nn.init.normal_(self.func2.weight, mean=0, std=1.0)
        torch.nn.init.normal_(self.func3.weight, mean=0, std=1.0)
    def forward(self, x):
        out = self.pool1(self.act1(self.conv1(x)))
        out = self.pool2(self.act2(self.conv2(out)))
        out = out.view(-1, 7 * 7 * 16)
        out = self.act3(self.func1(out))
        out = self.act4(self.func2(out))
        out = self.func3(out)
        return out


def train(model, loss_fn, optimizer, train_data, epochs, val_data):
    for epoch in range(epochs):
        print(epoch)
        loss = []
        device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
        for batch in train_data:
            img, label = batch
            img, label = img.to(device), label.to(device)
            predict = model(img)
            loss = loss_fn(predict, label)
            optimizer.zero_grad()
            loss.backward()
            optimizer.step()
        cnt = 0
        for img_val, label_val in val_data:
            predict = model(img_val)
            _, index = torch.max(predict, dim=1)
            cnt += (index == label_val)
        table_data = pandas.DataFrame({'epoch': epoch + 1, 'loss': loss, 'accuracy': 0.0001 * cnt})
        table_html = table_data.to_html(index=False)
        with open('data.html', 'a') as file:
            file.write(table_html)



data_path = '../MNIST/raw/'

train_data = torchvision.datasets.MNIST(root='.',
                                        train=True, transform=torchvision.transforms.ToTensor())
val_data = torchvision.datasets.MNIST(root='.',
                                      train=False,transform=torchvision.transforms.ToTensor())

train_data = torch.utils.data.DataLoader(train_data, batch_size=100, shuffle=True, pin_memory=True)
val_data = torch.utils.data.DataLoader(val_data, shuffle=True)

# for image, label in train_data:
#     plt.imshow(image.permute(1, 2, 0), cmap='gray')  # 将图像显示为灰度图
#     plt.title(f'Label: {label}')
#     plt.axis('off')  # 关闭坐标轴显示
#     plt.show()  # 显示图像
#     cv2.waitKey()

model = Net()


optimizer = optim.Adamax(model.parameters(), lr=0.005)

train(model, nn.CrossEntropyLoss(), optimizer, train_data, 30, val_data)

torch.save(model.state_dict(), 'model_params_CNN.pth')




