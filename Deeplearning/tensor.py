import torch


X = torch.randn(5, 3)
print('X:', X)
print('X.shape:', X.shape)
print('X.dtype:', X.dtype)
print('X.device:', X.device)

Y = torch.tensor([[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15]])
print('Y:', Y)
Y = Y.permute(1, 0)
print('new Y:', Y)

print('X + Y:', X + Y)
print('X - Y:', X - Y)
print('X * Y:', X * Y)
print('X / Y:', X / Y)

#绝对值
print('abs(X):', torch.abs(X))
#开方
print('sqrt(abs(X)):', torch.sqrt(torch.abs(X)))
#取反
print('neg(X):', torch.neg(X))
#求平均
print('mean(X) dim=1 :', torch.mean(X, dim=1))

#max
val, index = torch.max(X, dim=1)
print('val:', val)
print('index:', index)
#argmax最大值的index
index = torch.argmax(X,dim=1)
print('index:', index)
#sum
sum = torch.sum(X,dim=1)
print('sum:', sum)

#numpy
numpy = X.numpy()
print('it is a numpy:', numpy)
#tensor
X = torch.from_numpy(numpy)
print('it is a tensor:', X)

#转到cuda
X.to(device='cuda')
print('X.device:', X.device)