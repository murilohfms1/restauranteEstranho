#include <stdio.h>
#include <math.h>

float leItens()
{
    float qddItens;
    printf("entre com a quantidade de itens consumidos:\n");
    scanf("%f", &qddItens);

    if (qddItens > 4.00 || qddItens <= 0.00)
    {
        return leItens();
    }

    return qddItens;
}

int opCliente()
{
    int op;
    printf("entre com sua posicao no clube de vantagens:\n");
    
    printf("1 - Cliente comum\n");
    printf("2 - Cliente VIP\n");
    printf("3 - Funcionario\n");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        return 1;
    
    case 2:
        return 2;

    case 3:
        return 3;
    
    default:
        printf("entrada invalida, tente novamente\n");
        return opCliente();
    }

    return op;
}

float totalCvantagens(float subcontaAntiga)
{
    int op = opCliente();

    if (op == 1)
    {
        return subcontaAntiga;
    } else if (op == 2)
    {
        subcontaAntiga -= (1.00/10.00)*subcontaAntiga;
        return subcontaAntiga;
    } else 
    {
        if (subcontaAntiga > 50.00)
        {
            subcontaAntiga -= (2.00/10.00)*subcontaAntiga;
        }
        else
        {
            subcontaAntiga -= (1.00/10.00)*subcontaAntiga;
        }        
    }

    return subcontaAntiga;
}

float contaParcial()
{
    char nomeItem[100];
    float precoItem, qddIndividual;
    
    printf("entre com o nome do item:\n");
    scanf("%s", nomeItem);
    
    printf("entre com o preco do item:\n");
    scanf("%f", &precoItem);
    printf("entre com a quantidade consumida desse item:\n");
    scanf("%f", &qddIndividual);

    float subconta = precoItem*qddIndividual;

    if (qddIndividual <= 0.00 || precoItem <= 0.00)
    {
        printf("entrada invalida. tente novamente\n");
        return contaParcial();
    }

    return subconta;
}

float formaPag(float total_conta)
{
    int formaPagamento;

    printf("entre com a forma de pagamento dentre as listadas:\n");
    printf("1 - Dinheiro\n");
    printf("2 - Debito\n");
    printf("3 - Credito\n");
    printf("4 - PIX\n");
    scanf("%d", &formaPagamento);

    switch (formaPagamento)
    {
    case 1:
        total_conta -= (5.00/100.00)*total_conta;
        break;
        
    case 2:
        break;

    case 3:
        total_conta += (1.00/10.00)*total_conta;
        break;
    
    case 4:
        total_conta -= (7.00/100.00)*total_conta;
        break;

    default:
        printf("entrada invalida, tente novamente\n");
        return formaPag(total_conta);
    }

    if (formaPagamento == 1)
    {
        printf("forma escolhida: dinheiro em especie\n");
    } else if (formaPagamento == 2)
    {
        printf("forma escolhida: debito\n");
    } else if(formaPagamento == 3)
    {
        printf("forma escolhida: credito\n");
    } else 
    {
        printf("forma escolhida: pix\n");
    }

    return total_conta;
}

float avaliaRec(float qddtotal, float conta_acrescentada, float conta, float i)
{
    if ((int) i < (int) qddtotal)
    {
        conta_acrescentada = contaParcial();
        conta += conta_acrescentada;
        return avaliaRec(qddtotal, conta_acrescentada, conta, i + 1.00);
    }
    return conta;
}

float contacAcrescimo()
{
    float conta = 0.00, i = 0.00, conta_acrescentada = 0.00, total_conta, conta_inc;

    float qddtotal = leItens();
    
    conta_inc = avaliaRec(qddtotal, conta_acrescentada, conta, i);

    float subcontaPdcrescimos = totalCvantagens(conta_inc);
    total_conta = formaPag(subcontaPdcrescimos);
    
    if (total_conta > 100.00)
    {
        total_conta += (1.00/10.00)*total_conta;
        printf("taxa de servico a ser paga: 10%% da compra\n");
    }

    total_conta += (5.00/100.00)*total_conta;

    printf("taxa de servico a ser paga: 5%% da compra total\n");
    printf("valor total livre de descontos: %.2f\n", conta_inc);

    if (conta_inc != 0.00)
    {
        float desconto_total = total_conta/conta_inc;
        printf("desconto total aplicado a compra: %.2f%% do valor\n", (1 - desconto_total)*100);
    }

    return total_conta;
}

void mostraInfo()
{
    char nome[100];
    printf("entre com seu nome:\n");
    scanf("%s", nome);

    float total_conta = contacAcrescimo();
    printf("valor total a ser pago: %.2f\n", total_conta);
    printf("nome do cliente: %s\n", nome);
}

int main()
{
    mostraInfo();

    return 0;
}