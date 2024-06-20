import bisect

def find_ge(a, x):
    'Find leftmost item greater than or equal to x'
    i = bisect.bisect_left(a, x)
    if i != len(a):
        return a[i]
    else: return 0

x = int(input())
quartos = list(map(str,input().split()))
choroes = list(map(str,input().split()))
visitados = []
choroes_index = 0;

for i in quartos:
    choraodavez = choroes[choroes_index]
    
    while (find_ge(visitados, choraodavez)==choraodavez): # checa se o chorao atual ja foi visitado, caso sim, passa pro proxmo chorao
        choroes_index = choroes_index+1
        choraodavez = choroes[choroes_index]
    
    print(choraodavez, end=" ") # printa o chorão
    
    bisect.insort_left(visitados, i) # insere a criança do quarto atual nos visitados
        
    choroes_index = choroes_index+1 # anda o indice de choroes
print()