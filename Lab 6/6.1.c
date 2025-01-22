#include <stdio.h>

// Função que verifica se um ano é bissexto
int is_bissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

// Função que retorna o número de dias em um mês de um determinado ano
int dias_no_mes(int mes, int ano) {
    if (mes == 2) {
        return is_bissexto(ano) ? 29 : 28;
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    }
    return 31;
}

// Função que calcula a diferença em dias entre duas datas
int calcula_dias(int dia, int mes, int ano) {
    int dia_fixo = 17, mes_fixo = 9, ano_fixo = 2020;
    int dias = 0;
    
    // Incrementar até a data fixa
    while (ano < ano_fixo || (ano == ano_fixo && mes < mes_fixo) || (ano == ano_fixo && mes == mes_fixo && dia < dia_fixo)) {
        dia++;
        dias++;
        if (dia > dias_no_mes(mes, ano)) {
            dia = 1;
            mes++;
            if (mes > 12) {
                mes = 1;
                ano++;
            }
        }
    }
    
    // Incluir o dia final
    return dias + 1;
}

int main() {
    int dia, mes, ano;
    
    // Ler uma série de datas da entrada padrão
    while (scanf("%d %d %d", &dia, &mes, &ano) != EOF) {
        printf("%d\n", calcula_dias(dia, mes, ano));
    }
    
    return 0;
}
