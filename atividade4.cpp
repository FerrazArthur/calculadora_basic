#include<iostream>
#include<vector>
using namespace std;
double soma(double valor1, double valor2)
{
    return valor1+valor2;
}

double subtrai(double valor1, double valor2)
{
    return valor1-valor2;
}

double multiplica(double valor1, double valor2)
{
    return valor1*valor2;
}

double divide(double valor1, double valor2)
{
    try
    {
        if(valor2 != 0)
            return valor1 / valor2;
        else
            throw runtime_error("Erro durante operação: Tentativa de dividir por zero.\n");
    }
    catch(exception& e)
    {
        cerr<<"Ocorreu um "<<e.what();
    }
}

int ehPrimo(int valor1)
{
    for(int i = 2; i < valor1/2.0; i++)
        if(valor1%i == 0)
            return false;
    return 1;
}

int ehPar(int valor1)
{
    if(valor1 == 0 || valor1 % 2 != 0)
        return 0;
    else
        return 1;
}

int ehImpar(int valor1)
{
    if(valor1 == 0 || valor1 % 2 == 0)
        return 0;
    else
        return 1;
}

int ehMultiplo5(int valor5)
{
    if(valor5 == 0 || valor5 % 5 != 0)
        return 0;
    else
        return 1;
}

int ehPerfeito(int valor1)
{
   try{
       int soma = 1;
       if(valor1 < 0)
           throw runtime_error("Erro: função ehPerfeito não possui portabilidade para números negativos ainda\n");
       for(int i = 2; i <= valor1 / 2; i++)
           if(valor1 % i == 0)
               soma += i;
       if(soma == valor1 && soma != 1)
           return 1; 
   }
   catch(exception& e)
   {
       cerr<<e.what();
   }
   return 0; 
}

int ehPositivo(double valor1)
{
    return (valor1>0)? 1:0;
}

void executaDois(double (*op) (double, double))
{
    double val1, val2;
    cout<<"insira o valor 1:\n";
    cin>>val1;
    cout<<"inseria o valor 2:\n";
    cin>>val2;
    cout<<"resultado: "<<(*op) (val1, val2)<<endl;
}

void executaUm(int (*op) (auto))
{
    double val1, val2;
    vector<int> aux;
    do
    {
        cout<<"insira o limite inferior do intervalo:\n";
        cin>>val1;
        cout<<"insira o limite superior do intervalo:\n";
        cin>>val2;
        if(val1 > val2)
            cout<<"intervalo inválido, por favor insira um limite superior que seja >>superior<< ao limite inferior!\n";
    }while(val1 > val2);
    while(val1 <= val2)
        aux.push_back(val1++);
    for(int i = 0; i < aux.size(); i++)
        (*op) (aux[i])? cout<<aux[i]<<" testou positivo\n": cout;
}

void menuMainTxt()
{
    cout<<"<A> visualizar menu algebrico\n"
    <<"<T> visualizar menu de verificações\n"
    <<"<S> sair\n";
}

void menuAlgebraTxt()
{
    cout<<"<+> somar dois valores\n"
    <<"<-> subtrair dois valores\n"
    <<"<*> multiplicar dois valores\n"
    <<"</> dividir dois valores\n"
    <<"<V> voltar\n";
}

void menuComparaTxt()
{
    
    cout<<"<2> verificar se é par\n"
    <<"<I> verificar se é impar\n"
    <<"<P> verificar se é primo\n"
    <<"<F> verificar se é perfeito\n"
    <<"<5> verificar se é multiplo de 5\n"
    <<"<+> verificar se é positivo\n"
    <<"<V> voltar\n";
}

void menuAlgebra()
{
    char control;
    while(1)
    {
        menuAlgebraTxt();
        cin>>control;
        switch(control)
        {
            case '+':
                executaDois(soma);
                break;
            case '-':
                executaDois(subtrai);
                break;
            case '*':
                executaDois(multiplica);
                break;
            case '/':
                executaDois(divide);
                break;
            case 'V': case 'v':
                return;
           default:
                cout<<"Opção não disponível, tente uma opção válida\n";
        }
    }
}

void menuCompara()
{
    char control;
    while(1)
    {
        menuComparaTxt();
        cin>>control;
        switch(control)
        {
            case '2':
                executaUm(ehPar);
                break;
            case 'I': case 'i':
                executaUm(ehImpar);
                break;
            case 'P': case 'p':
                executaUm(ehPrimo);
                break;
            case 'F': case 'f':
                executaUm(ehPerfeito);
                break;
            case '5':
                executaUm(ehMultiplo5);
                break;
            case '+':
                executaUm(ehPositivo);
                break;
            case 'V': case 'v':
                return;
            default:
                cout<<"Opção não disponível, tente uma opção válida\n";
        }
    }
}

void menuMain()
{
    char control;
    while(1)
    {
        menuMainTxt();
        cin>>control;
        switch(control)
        {
            case 'A': case 'a':
                menuAlgebra();
                break;
            case 'T': case 't':
                menuCompara();
                break;
            case 'S': case 's':
                cout<<"Encerrando execução, volte sempre\n";
                return;
           default:
                cout<<"Opção não disponível, tente uma opção válida\n";
        }
    }
}

int main()
{
    menuMain();
    return 0;
}
