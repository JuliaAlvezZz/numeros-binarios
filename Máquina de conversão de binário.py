import math  ##importa biblioteca com algumas funções matemáticas

def config(): ##função para definir os valores da máquina
    global n, l, u
    n=int(input('Digite o número de algarismos na mantissa:')) ##em python o input gera uma string
    l=int(input('Digite o menor valor do expoente:')) ##a função int antes do input transforma a string em int caso o conteúdo seja um número inteiro
    u=int(input('Digite o maior valor do expoente:'))
    op=int(input('Digite 0 continuar ou 1 para alterar a configuração:'))
    if op==0:
       return
    else:
        config()

def mult(numF): ##função que recebe parte fracionária do número e a converte para binário
    global numB ##string global em que será armazenado o número convertido
    numF=numF*2 ##são feitas sucessivas multiplicações por 2
    if numF==0: 
        numB=numB+'0'
        return
    if numF>1:
        numB=numB+'1'
        numF=numF-1
        mult(numF)
    elif numF<1:
        numB=numB+'0'
        mult(numF)
    elif numF==1:
        numB=numB+'1'
        return

def div(numI): ##função que recebe parte inteira do número e a converte para binário
    return bin(numI) ##ela é meio inútil pq só usa uma função já definida em python

def convert(num): ##função que converte número para binário
    global numB
    numI=int(num/1) ##variável recebe parte inteira do número (usei a função int só para ter certeza que não vai haver nenhuma surpresa)
    numF=num-numI ##variável recebe parte fracionária a partir da diferença do número original pela parte inteira (aqui acontece aquela mágica de surgir 0000000009)
    numIB=str(div(numI))+'.' ##chama função que converte a parte inteira e adiciona o ponto que separa inteiro de fracionário
    numB=numB+numIB[2:] ##a variável que terá o número convertido recebe a parte inteira convertida a partir da segunda posição da string (pq na conversão fica, por ex: 2=0b10, então eu tiro o 0b)
    if numF!=0: ##se houver parte fracionária, é chamada a função que a converte
        numFB=str(mult(numF))

def soma1(): ##função que soma 1 ao número convertido e já em C1
    global numC2
    for i in range(len(numC2)-1, -1, -1): ##dado o tamanho da string, é feita uma iteração de trás para frente verificando se cada valor é 0 ou 1
        if numC2[i]!='1' and numC2[i]=='0': ##caso encontre um valor 0, é realizada a condição
            numC2=numC2[:i]+'1'+numC2[i+1:] ##em python não é possível alterar o conteúdo da string em partes, com apenas uma atribuição, então é recebida a parte antes do valor a ser alterado, o valor desejado e a parte a seguir
            return
        if numC2[i]=='1': ##caso encontre um valor 1
            numC2=numC2[:i]+'0'+numC2[i+1:] ##é realizada a mesma operação da condição anterior, apenas trocando o 1 por 0
    
def toBin(): ##função que organiza as conversões
    global numB, num, numSA, numC1, numC2
    numB='' ##é necessário preencher a string antes de manipular
    if num<0: ##conversão caso o número seja negativo
        convert(num*(-1)) ##ele e convertido como se fosse um número positivo
        numSA='1'+numB ##sinal e amplitude com sinal=1
        numC1=numB.replace('0', 'u') ##começa o complemento de 1 substituido 0 por uma letra qualquer (no caso u)
        numC1=numC1.replace('1', '0') ##troca 1 por 0
        numC1=numC1.replace('u', '1') ##termina o complemento trocando u por 1
        numC2=numC1 ##string de C2 recebe string de C1
        soma1() ##função que soma 1 ao complemento de 1
        print('\nMódulo:', numB,'\nSinal e Amplitude:', numSA,'\nComplemento de 1:', numC1,'\nComplemento de  2:', numC2) ##exibe o número convertido e suas representações negativas
    else: ##conversão para número positivo
        convert(num)
        if num%1==0: ##caso o número seja somente inteiro
            print('\nValor binário:', numB.replace('.', '')) ##exibe o valor sem o ponto que é adicionado após o inteiro
        else:
            print('\nValor binário:', numB)

def normal(): ##função para normalizar o valor
    global numB, numN, k
    p=numB.find('.') ##a partir da posição do ponto é feita a normalização
    numN=''
    if num>=0: ##caso o número seja positivo
        if num>=1: ##caso seja maior que 1
            numN=numB[:p]+numB[p+1:] ##recebe a string sem o ponto
            if len(numN)>n: ##verifica se o tamanho excede a mantissa
                numN=numN[:n] ##caso exceda, realiza o truncamento e é exibida a mensagem de erro
                print('Truncamento!')
            print('Valor normalizado: 0 ,',numN,' * 2^',p) ##exibe a normalização
            k=p
        else: ##caso seja menor que 1
            numN=numB[p+1:] ##recebe string após o ponto
            x=0 ##variável para contar quantidade de 0 após o ponto
            for i in range(0, len(numN)): ##iteração para percorrer string até encontrar 1
                if numN[i]=='1': ##caso encontre 1, a string recebe apenas o que vier do 1 em diante e para a iteração
                    numN=numN[i:]
                    break
                else: ##caso encontre 0, o x é incrementado
                    x+=1
            if len(numN)>n: ##verifica se o tamanho excede a mantissa
                numN=numN[:n]
                print('Truncamento!')
            print('Valor normalizado: 0 ,',numN,' * 2^',-x)
            k=-x
    else: ##caso o número seja negativo, ele realiza as mesmas funções, apenas com as alterações necessárias
        if -num>=1:
            numN=numB[:p]+numB[p+1:]
            if len(numN)>n:
                numN=numN[:n]
                print('Truncamento!')
            print('Valor normalizado em S/A: 1 ,',numN,' * 2^',p)
            k=p
        else:
            numN=numB[p+1:]
            x=0
            for i in range(0, len(numN)):
                if numN[i]=='1':
                    numN=numN[i:]
                    break
                else:
                    x+=1
            if len(numN)>n:
                numN=numN[:n]
                print('Truncamento!')
            print('Valor normalizado em S/A: 1 ,',numN,' * 2^',-x)
            k=-x
    if k>u: ##caso o expoente armazenado seja maior que o u da máquina
        print('Overflow!')
    if k<l: ##caso o expoente armazenado seja menor que o l da máquina
        print('Underflow!')

def toDec(): ##função que pega a string normalizada e converte para decimal
    global numA, k
    numA=0 ##zera a variável que vai receber valor decimal
    for i in range(0, len(numN)): ##iteração para percorrer string normalizada
        if numN[i]=='1': ##caso conteúdo na posição seja 1, é feita a soma a partir da posição
            numA=math.fsum([numA,(1/(math.pow(2, i+1)))]) ##função de soma da biblioteca math (usei para testar se a precisão seria aumentada, mas nao foi o caso)
    numA=numA*(math.pow(2, k)) ##realiza a potenciação a partir de outra função da biblioteca math
    if num>=0: ##caso o número seja positivo é exibido o módulo
        print('Valor decimal armazenado:', numA)
    if num<0: ##caso seja negativo, é exibido seu oposto
        print('Valor decimal armazenado:', -numA)

def numero(): ##função para manipular as funções
    global num, numN, numB
    print('\nF( 2 ,',n,',',l,',',u,')') ##exibe configuração da máquina
    num=float(input('\nDigite um número decimal:')) ##pega número digitado pelo usuário e transforma em float
    toBin() ##função que converte para binário
    normal() ##função que normaliza
    toDec() ##função que "desconverte"
    del numN ##apaga variável para não haver lixo quando for reutilizada
    del numB
    op=int(input('\nDigite 0 para utilizar a mesma configuração ou 1 para alterá-la:'))
    if op==0:
        numero()
    else:
        menu()
    
def menu(): ##função que chama funções principais
    config()
    numero()

menu() ##primeira função a ser executada (como se fosse o "main" do python)
