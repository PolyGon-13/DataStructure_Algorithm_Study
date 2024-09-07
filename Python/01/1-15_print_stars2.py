print('*를 출력합니다.')
n=int(input('몇 개를 출력할까요? : '))
w=int(input('몇 개마다 출바꿈할까요? : '))

for i in range(n//w):
    print('*'*w)
    
rest=n%w
if rest:
    print('*'*rest)
