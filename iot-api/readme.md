# Para rodar o servico no docker, baixe o docker e rode os seguintes comandos:

```bash
docker-compose build
docker-compose up -d
```

#APIs presentes nesse projeto e seus respectivos endereços e campos:

```bash
BoletimOcorrencias

/api/policia/boletimocorrencia

{
	Titulo
	Descrição
	Segmento
	Status
	Data e Hora
	Latitude
	Longitude
	Data de Criação
	Data de Última Atualização
}
```

```bash
Chamados

/api/chamados

{
	Alias
	Titulo
	Descrição
	Segmento
	Fotos
	Status
	Data e Hora
	Latitude
	Longitude
}
```

```bash
Paciente

/api/paciente

{
	Alias
	Nome
	Data de Criação
}
```

```bash
PedidoReforcos

/api/policia/pedidoreforcos

{
	Titulo
	Descrição
	Segmento
	Status
	Data e Hora
	Latitude
	Longitude
	Data de Criação
	Data de Última Atualização
}
```

```bash
Sensores

/api/sensores

{
	Alias
	Nome
	Tipo
	Data de Criação
	Data de Última Atualização
	Valor
	Localização
}
```

```bash
Vitimas

/api/vitima

{
	Alias
	Nome
	Data de Criação
	Localização
	Deambulando
	Respiração
	RespiraViasAéreas
	ReenchimentoCapilar
	PulsoRadial
	CumpreOrdens
	Status
}
```
