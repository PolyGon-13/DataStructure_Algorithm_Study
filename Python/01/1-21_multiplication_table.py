print('-'*27)
for i in range(1,10):
    for j in range(1,10):
        print(f'{i*j:3}',end='') # :3 에 의해 출력값이 3자리보다 작으면 공백으로 매꿔짐
    print()
print('-'*27)
