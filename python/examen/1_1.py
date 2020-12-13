def f(x,n):
    """función de reacción.
        si > 200 => tóxico
    """
    #primero chequear si x,n están en los rangos y n es entero
    if (x>=0 and x<=10) and (n>=0 and n<=5) and isinstance(n, int):
        return -(x-n)**4 + (10-n)*x**2 - x -15

def rango_toxico(n):
    valores_toxicos = []
    x=0
    while x<=10:
        react =  f(x,n)
        if react > 200:
            valores_toxicos.append(x)
        x+=0.01
    
    if len(valores_toxicos) == 0:
        return "seguro"
    else:
        return f"{min(valores_toxicos)} < x < {max(valores_toxicos)}"

def analisis_seguridad():
    file_name = "safety_analysis_result.txt"
    with open(file_name, 'w') as file:
        file.write("Autores: Jimim, Suga, y Jungkook\n")
        for n in range(6):
            file.write(f"n={n} : {rango_toxico(n)}\n")
    
n = int(input("ingrese n: "))
print("Rango de peligrosidad de x para n =",n,":",rango_toxico(n))
analisis_seguridad()
