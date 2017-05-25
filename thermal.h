#ifndef THERMAL_H
#define THERMAL_H

typedef struct {
	unsigned short port;
	unsigned short temperature;
} thermometer;

void setup_thermocouples(char ports)
{
	// configura as entradas AN0, AN1 e AN3 como entradas analógicas
	ANSEL  = ports;

	#warning Voltage reference not configured
	
	// liga o conversor ADC 
	// Obs. o mesmo registrador seleciona o canal utilizado
	ADCON0 = 0x01;

	// configura a saída do ADC como justificada para a direitae a referência de tensão como a fonte
	ADCON1 = 0x80;

	
}

void measure_temperature(themometer** therms, int size)
{
	// realiza as medições para todos os termometros
	for (int i = 0; i < size; i++)
	{
		// seleciona a porta do termopar e inicia a conversão
		ADCON0 = thermometer[i]->port << 2 + 3;
		
		// espera o fim da conversão
		while (ADCON0 & 0x02);
		
		// guarda o valor medido
		#warning Constante de conversão não configurada
		thermometer[i]->temperature = (ADRESL >> 6) + (ADRESH << 2);
		
	}	
}

#endif
