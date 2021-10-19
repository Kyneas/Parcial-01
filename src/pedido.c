#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "cliente.h"
#include "inputs.h"
#include "pedido.h"

/// @fn int NewID()
/// @brief Genera un ID unico para un pedido
///
/// @return ID Unico
static int NewID();

/// @fn int VerificarProcesamiento(int*, int*, int*, int)
/// @brief Valida que la carga de HDPE, LDPE y PP sean correctas y no superen el total
///
/// @param hdpe Direccion de memoria donde se guardara la cantidad de HDPE
/// @param ldpe Direccion de memoria donde se guardara la cantidad de LDPE
/// @param pp Direccion de memoria donde se guardara la cantidad de PP
/// @param kilosTotales Cantidad de kilos totales disponibles para procesar
/// @return -2 por lista nula/largo invadilo, 0 si se pudo procesar
static int VerificarProcesamiento(float * hdpe, float * ldpe, float * pp, float kilosTotales);

/// @fn void MostrarPedidoPendiente(ePedido)
/// @brief  Muestra ID, kilos totales y el ID del cliente de 1 pedido
///
/// @param pedido Pedido a mostrar
static void MostrarPedidoPendiente(ePedido pedido);

int InicializarListaPedidos(ePedido lista[], int len)
{
	int retorno = -1;
	if(lista != NULL && len > 1)
	{
		for (int i = 0 ; i < len ; i++)
		{
			lista[i].isEmpty = 1;
		}

		retorno = 0;
	}
 return retorno;
}

int NuevoPedido(ePedido listaPedidos[], int len, int idCliente)
{
	int retorno = -2;

	if(listaPedidos != NULL && len > 1)
	{
		for(int i = 0 ; i < len ; i++)
		{
			retorno = -1;

			if(listaPedidos[i].isEmpty)
			{
				listaPedidos[i].kilosTotales = PedirFlotantePositivo("\nIngrese los kilos a recolectar: ", "\nError");
//				listaPedidos[i].kilosTotales = PedirEnteroPositivo("\nIngrese los kilos a recolectar: ", "\nError");
				listaPedidos[i].idCliente = idCliente;
				listaPedidos[i].estado = PENDIENTE;
				listaPedidos[i].isEmpty = 0;
				listaPedidos[i].HDPE = 0;
				listaPedidos[i].LDPE = 0;
				listaPedidos[i].PP = 0;
				listaPedidos[i].idPedido = NewID();
				retorno = listaPedidos[i].idPedido;
				break;

			}
		}
	}

	return retorno;
}

//void MostrarPedido(ePedido pedido)
//{
//	printf("\n%-4d %-12d %-4d %-14s %-4d %-4d %-4d", pedido.idPedido, pedido.kilosTotales, pedido.idCliente, pedido.estado, pedido.HDPE, pedido.LDPE, pedido.PP);
//}
//
//int MostrarListaPedidos(ePedido listaPedidos[], int len)
//{
//	int retorno = -1;
//
//	if(listaPedidos != NULL && len > 1)
//	{
//		for(int i = 0 ; i < len ; i++)
//		{
//			if(!listaPedidos[i].isEmpty)
//			{
//
//				MostrarPedido(listaPedidos[i]);
//				retorno = 0;
//			}
//		}
//	}
//
//	return retorno;
//}

int MostrarListaPedidosPendientes(ePedido listaPedidos[], int len)
{
	int retorno = -1;
	int flagPrimero = 1;

	if(listaPedidos != NULL && len > 1)
	{
		for(int i = 0 ; i < len ; i++)
		{
			if(!listaPedidos[i].isEmpty && listaPedidos[i].estado == PENDIENTE)
			{
				if(flagPrimero)
				{
					printf("ID   KILOS TOTALES    ID CLIENTE");
				}

				MostrarPedidoPendiente(listaPedidos[i]);
				flagPrimero=0;
				retorno = 0;
			}
		}
	}

	return retorno;
}

static void MostrarPedidoPendiente(ePedido pedido)
{
	printf("\n%-4d %.2fKg\t      %-4d", pedido.idPedido, pedido.kilosTotales, pedido.idCliente);
}

int ProcesarPedido(ePedido listaPedidos[], int len, int idPedido)
{
	int retorno = -2;

	if(listaPedidos != NULL && len > 1)
	{
		for(int i = 0 ; i < len ; i++)
		{
			if(!listaPedidos[i].isEmpty && listaPedidos[i].idPedido == idPedido && listaPedidos[i].estado == COMPLETADO)
			{
				retorno = -1;
				break;
			}
			if(!listaPedidos[i].isEmpty && listaPedidos[i].idPedido == idPedido)
			{
				printf("\nLos kilos totales son: %.2f", listaPedidos[i].kilosTotales);

				retorno = VerificarProcesamiento(&listaPedidos[i].HDPE, &listaPedidos[i].LDPE, &listaPedidos[i].PP, listaPedidos[i].kilosTotales);

				if(retorno == 0)
				{
					listaPedidos[i].estado = COMPLETADO;
				}

				break;
			}
		}
	}

	return retorno;
}

static int VerificarProcesamiento(float * hdpe, float * ldpe, float * pp, float kilosTotales)
{
	int retorno = -2;
	float polieAlta;
	float polieBaja;
	float polipropileno;
	float acumulador = 0;
	int flagError = 0;

	if(hdpe != NULL && ldpe != NULL && pp != NULL)
	{
		do
		{
			if(flagError)
			{
				printf("\nError, los kilos procesados no pueden superar el total de %.2f. Ingrese una cantidad valida.",kilosTotales);
				acumulador = 0;
			}

			flagError = 1;

			polieAlta = PedirFlotantePositivo("\nIngrese los kilos correspondientes a Polietileno de Alta Densidad: ", "\nError");
			acumulador += polieAlta;
		}while(acumulador > kilosTotales);

		flagError = 0;

		do
		{
			if(flagError)
			{
				printf("\nError, los kilos procesados no pueden superar el total de %.2f. Ingrese una cantidad valida.",kilosTotales);
				acumulador -= polieBaja;
			}

			flagError = 1;

			polieBaja = PedirFlotantePositivo("\nIngrese los kilos correspondientes a Polietileno de Baja Densidad: ", "\nError");

			acumulador += polieBaja;

		}while(acumulador > kilosTotales);

		flagError = 0;

		do
		{
			if(flagError)
			{
				printf("\nError, los kilos procesados no pueden superar el total de %.2f. Ingrese una cantidad valida.",kilosTotales);
				acumulador -= polipropileno;
			}

			flagError = 1;

			polipropileno = PedirFlotantePositivo("\nIngrese los kilos correspondientes a Polipropileno: ", "\nError");

			acumulador += polipropileno;

		}while(acumulador > kilosTotales);

		*hdpe = polieAlta;
		*ldpe = polieBaja;
		*pp = polipropileno;

		retorno = 0;
	}

	return retorno;
}

int HayPedido(ePedido lista[], int len)
{
	int retorno = 0;

	if(lista != NULL && len > 1)
	{
		for(int i = 0 ; i < len ; i++)
		{
			if(!lista[i].isEmpty)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

int HayPedidoCompletado(ePedido lista[], int len)
{
	int retorno = 0;

	if(lista != NULL && len > 1)
	{
		for (int i = 0 ; i < len ; i++)
		{
			if (!lista[i].isEmpty && lista[i].estado == COMPLETADO)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

int HayPedidoPendiente(ePedido lista[], int len)
{
	int retorno = 0;

	if(lista != NULL && len > 1)
	{
		for (int i = 0 ; i < len ; i++)
		{
			if (!lista[i].isEmpty && lista[i].estado == PENDIENTE)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

int BuscarPosicionPedidosPorID(ePedido lista[], int len, int id)
{
	int retorno = -1;

	if(lista != NULL && len > 1)
	{
		for(int i = 0 ; i < len ; i++)
		{
			if(!lista[i].isEmpty && lista[i].idPedido == id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int BajaPedidoPorIDCliente (ePedido lista[], int len, int idCliente)
{
	int retorno = -1;

	if(lista != NULL && len > 1)
	{
		for(int i = 0 ; i < len ; i++)
		{
			if(!lista[i].isEmpty && lista[i].idCliente == idCliente)
			{
				lista[i].isEmpty = 1;
				retorno = 0;
			}
		}
	}

	return retorno;
}

static int NewID()
{
	static int id = 0;
	id++;
	return id;
}
