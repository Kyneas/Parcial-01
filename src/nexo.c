#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cliente.h"
#include "inputs.h"
#include "pedido.h"
#include "nexo.h"

/// @fn void MostrarClienteYPendientes(eCliente, int, eLocalidad[], int)
/// @brief Muestra un cliente y la cantidad de pedidos pendientes
///
/// @param cliente Cliente a mostrar ID, nombre CUIT, direccion y localidad
/// @param pendientes Cantidad de cliente del cliente a mostrar
/// @param localidades Lista de localidades
/// @param lenLocalidades Largo de la lista de localidades
static void MostrarClienteYPendientes(eCliente cliente, int pendientes, eLocalidad localidades[], int lenLocalidades);

/// @fn void MostrarPedidoPendienteYDatosCliente(eCliente, ePedido, eLocalidad[], int)
/// @brief Muestra 1 pedido pendiente y los datos del cliente correspondiente
///
/// @param cliente Cliente a mostrar
/// @param pedido Pedido Pendiente a mostrar
/// @param localidades Lista de localidades
/// @param lenLocalidades Largode la lista de localidades
static void MostrarPedidoPendienteYDatosCliente (eCliente cliente, ePedido pedido, eLocalidad localidades[], int lenLocalidades);

/// @fn void MostrarPedidoPendienteYDatosCliente(eCliente, ePedido, eLocalidad[], int)
/// @brief Muestra 1 pedido completado y los datos del cliente correspondiente
///
/// @param cliente Cliente a mostrar
/// @param pedido Pedido Completado a mostrar
/// @param localidades Lista de localidades
/// @param lenLocalidades Largode la lista de localidades
static void MostrarPedidoCompletadoYCliente(eCliente cliente, ePedido pedido, eLocalidad localidades[], int lenLocalidades);

int ClientesConMasPendientes (eCliente listaClientes[], int len,ePedido listaPedidos[], int lenPedidos)
{
	int retorno = -1;

	eAuxiliar auxiliar[len];
	int mayorCantidad;
	int flag = 1;

	if (listaClientes != NULL && len > 0 && listaPedidos != NULL && lenPedidos > 0)
	{
		for (int i = 0 ; i < len ; i++)
		{
			if (!listaPedidos[i].isEmpty)
			{
				auxiliar[i].id = listaClientes[i].id;
				auxiliar[i].contador = 0;
			}
		}

		for (int i = 0 ; i < len ; i++)
		{
			if (!listaClientes[i].isEmpty)
			{
				for (int j = 0 ; j < lenPedidos ; j++)
				{
					if (!listaPedidos[j].isEmpty && auxiliar[i].id == listaPedidos[j].idCliente && listaPedidos[j].estado == PENDIENTE)
					{
						auxiliar[i].contador++;
					}
				}
			}
		}

		for (int i = 0 ; i < len ; i++)
		{
			if(!listaClientes[i].isEmpty && (flag || auxiliar[i].contador > mayorCantidad))
			{
				mayorCantidad = auxiliar[i].contador;
				flag = 0;
			}
		}

		printf("\nEl/Los clientes con mayor cantidad de pedidos pendientes es/son: "
			   "\nID       NOMBRE");
		for (int i = 0 ; i < len ; i++)
		{
			if (!listaClientes[i].isEmpty && mayorCantidad == auxiliar[i].contador)
			{
				printf("\n%-8d %-18s", listaClientes[i].id, listaClientes[i].name);
			}
		}

		retorno = 0;
	}

	return retorno;
}

int ClientesConMasCompletados (eCliente listaClientes[], int len,ePedido listaPedidos[], int lenPedidos)
{
	int retorno = -1;

	eAuxiliar auxiliar[len];
	int mayorCantidad;
	int flag = 1;

	if (listaClientes != NULL && len > 0 && listaPedidos != NULL && lenPedidos > 0)
	{
		for (int i = 0 ; i < len ; i++)
		{
			if (!listaPedidos[i].isEmpty)
			{
				auxiliar[i].id = listaClientes[i].id;
				auxiliar[i].contador = 0;
			}
		}

		for (int i = 0 ; i < len ; i++)
		{
			if (!listaClientes[i].isEmpty)
			{
				for (int j = 0 ; j < lenPedidos ; j++)
				{
					if (!listaPedidos[j].isEmpty && auxiliar[i].id == listaPedidos[j].idCliente && listaPedidos[j].estado == COMPLETADO)
					{
						auxiliar[i].contador++;
					}
				}
			}
		}

		for (int i = 0 ; i < len ; i++)
		{
			if(!listaClientes[i].isEmpty && (flag || auxiliar[i].contador > mayorCantidad))
			{
				mayorCantidad = auxiliar[i].contador;
				flag = 0;
			}
		}

		printf("\nEl/Los clientes con mayor cantidad de pedidos completados es/son: "
			   "\nID       NOMBRE");
		for (int i = 0 ; i < len ; i++)
		{
			if (!listaClientes[i].isEmpty && mayorCantidad == auxiliar[i].contador)
			{
				printf("\n%-8d %-18s", listaClientes[i].id, listaClientes[i].name);
			}
		}

		retorno = 0;
	}

	return retorno;
}

int MostrarClientesConPedidosPendientes(eCliente listaClientes[], int len,ePedido listaPedidos[], int lenPedidos, eLocalidad localidades[], int lenLocalidades)
{
	int retorno = -1;
	int contador = 0;
	int primeraVuelta = 1;

	if(listaClientes != NULL && len > 0 && listaPedidos != NULL && lenPedidos > 0 && localidades != NULL && lenLocalidades > 0)
	{
		for (int i = 0 ; i < len ; i++)
		{
			for (int j = 0 ; j < lenPedidos ; j++)
			{
				if(!listaClientes[i].isEmpty && !listaPedidos[j].isEmpty && listaClientes[i].id == listaPedidos[j].idCliente && listaPedidos[j].estado == PENDIENTE)
				{
					contador++;

				}
			}

			if(primeraVuelta && !listaClientes[i].isEmpty)
			{
				printf("\nID   NOMBRE           CUIT           DIRECCION        CIUDAD           PEDIDOS PENDIENTES");
				primeraVuelta = 0;
				retorno = 0;
			}

			if (!listaClientes[i].isEmpty)
			{
				MostrarClienteYPendientes(listaClientes[i],contador, localidades, lenLocalidades);
			}
			contador = 0;

		}
	}

	return retorno;
}

int BajaClienteV2(eCliente lista[], int len,ePedido listaPedidos[], int lenPedidos, int id)
{
	int retorno = -1;

	if(lista != NULL && len > 1)
	{
		for(int i = 0 ; i < len ; i++)
		{
			if(lista[i].id == id && !lista[i].isEmpty)
			{
				lista[i].isEmpty = 1;

				BajaPedidoPorIDCliente(listaPedidos, lenPedidos, lista[i].id);
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

static void MostrarClienteYPendientes(eCliente cliente, int pendientes, eLocalidad localidades[], int lenLocalidades)
{
	for (int i = 0 ; i < lenLocalidades ; i++)
	{
		if(cliente.city == localidades[i].id)
		{
			printf("\n%-4d %-16s %-14.0lf %-16s %-16s %-8d",cliente.id, cliente.name,cliente.cuit,cliente.adress,localidades[i].descripcion,pendientes);
			break;
		}

	}

}

int MostrarPedidosPendientesYDatosCliente(eCliente listaClientes[], int len,ePedido listaPedidos[], int lenPedidos, eLocalidad localidades[], int lenLocalidades)
{
	int retorno = -1;
	int primeraVuelta = 1;

	if(listaClientes != NULL && len > 0 && listaPedidos != NULL && lenPedidos > 0 && localidades != NULL && lenLocalidades > 0)
	{
		for (int i = 0 ; i < len ; i++)
		{
			for(int j = 0 ; j < lenPedidos ; j++)
			{
				if(!listaClientes[i].isEmpty && !listaPedidos[j].isEmpty && listaClientes[i].id == listaPedidos[j].idCliente && listaPedidos[j].estado == PENDIENTE)
				{
					if(primeraVuelta)
					{
						printf("\nID PEDIDO  KILOS A RECOLECTAR   ID CLIENTE   NOMBRE         CUIT           DIRECCIÓN      CIUDAD");
						primeraVuelta = 0;
					}
					MostrarPedidoPendienteYDatosCliente (listaClientes[i], listaPedidos[j], localidades, lenLocalidades);
					retorno = 0;

				}
			}
		}
	}

	return retorno;
}

static void MostrarPedidoPendienteYDatosCliente (eCliente cliente, ePedido pedido, eLocalidad localidades[], int lenLocalidades)
{
	for(int i = 0 ; i < lenLocalidades ; i++)
	{
		if(cliente.city == localidades[i].id)
		{
			printf("\n%-10d %-20.2f %-12d %-14s %-14.0lf %-14s %-14s",pedido.idPedido, pedido.kilosTotales,cliente.id,cliente.name, cliente.cuit, cliente.adress, localidades[i].descripcion);
			break;
		}

	}

}

int MostrarPedidosCompletadosYDatosCliente(eCliente listaClientes[], int len,ePedido listaPedidos[], int lenPedidos, eLocalidad localidades[], int lenLocalidades)
{
	int retorno = -1;
	int primeraVuelta = 1;

	if(listaClientes != NULL && len > 0 && listaPedidos != NULL && lenPedidos > 0 && localidades != NULL && lenLocalidades > 0)
	{
		for (int i = 0 ; i < len ; i++)
		{
			for(int j = 0 ; j < lenPedidos ; j++)
			{
				if(!listaClientes[i].isEmpty && !listaPedidos[j].isEmpty && listaClientes[i].id == listaPedidos[j].idCliente && listaPedidos[j].estado == COMPLETADO)
				{
					if(primeraVuelta)
					{
						printf("\nID PEDIDO  HDPE       LDPE       PP         ID CLIENTE   NOMBRE         CUIT           DIRECCIÓN      CIUDAD");
						primeraVuelta = 0;
					}
					MostrarPedidoCompletadoYCliente (listaClientes[i], listaPedidos[j],localidades, lenLocalidades);
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

static void MostrarPedidoCompletadoYCliente(eCliente cliente, ePedido pedido, eLocalidad localidades[], int lenLocalidades)
{
	for (int i = 0 ; i < lenLocalidades ; i++)
	{
		if(cliente.city == localidades[i].id)
		{
			printf("\n%-10d %-10.2f %-10.2f %-10.2f %-12d %-14s %-14.0lf %-14s %-14s",pedido.idPedido, pedido.HDPE, pedido.LDPE, pedido.PP,cliente.id,cliente.name, cliente.cuit, cliente.adress, localidades[i].descripcion);
			break;
		}
	}

}

int BuscarPendientesParaLocalidad(eCliente listaClientes[], int len,ePedido listaPedidos[], int lenPedidos,eLocalidad localidades[], int lenLocalidades,int  idLocalidad)
{
	int retorno = -2;
	int contador = 0;

	if(listaClientes != NULL && len > 0 && listaPedidos != NULL && lenPedidos > 0 && localidades != NULL && lenLocalidades > 0)
	{
		retorno = -1;

		for (int i = 0 ; i < len ; i++)
		{
			if (!listaClientes[i].isEmpty && listaClientes[i].city == idLocalidad)
			{
				for (int j = 0 ; j < lenLocalidades ; j++)
				{
					if (!localidades[j].isEmpty && localidades[j].id == idLocalidad)
					{
						for (int o = 0 ; o < lenPedidos ; o++)
						{
							if (!listaPedidos[o].isEmpty && listaPedidos[o].idCliente == listaClientes[i].id && listaPedidos[o].estado == PENDIENTE)
							{
								contador++;
							}
						}
					}
				}
			}
		}
	}

	if(contador > 0)
	{
		retorno = contador;
	}

	return retorno;
}

float CalcularPromedioPP(eCliente listaClientes[], int len,ePedido listaPedidos[], int lenPedidos)
{
	float retorno = -1;
	int acumuladorPP = 0;
	int contadorClientes = 0;

	if(listaClientes != NULL && len > 0 && listaPedidos != NULL && lenPedidos > 0)
	{
		for (int i = 0 ; i < lenPedidos ; i++)
		{
			if(!listaPedidos[i].isEmpty && listaPedidos[i].estado == COMPLETADO)
			{
				for (int j = 0 ; j < len ; j++)
				{
					if (!listaClientes[j].isEmpty && listaPedidos[i].idCliente == listaClientes[j].id)
					{
						acumuladorPP += listaPedidos[i].PP;
						contadorClientes++;
					}
				}
			}

		}
	}

	if(contadorClientes > 0)
	{
		retorno = (float)acumuladorPP/contadorClientes;
	}

	return retorno;
}

int BajaLocalidad(eCliente listaClientes[], int lenClientes,ePedido listaPedidos[], int lenPedidos,eLocalidad localidades[], int lenLocalidades,int  idLocalidad)
{
	int retorno = -1;

	if (localidades != NULL && lenLocalidades > 0 && listaClientes != NULL && lenClientes > 0 && listaPedidos != NULL && lenPedidos > 0)
	{
		for (int i = 0 ; i < lenLocalidades ; i++)
		{
			if (localidades[i].id == idLocalidad && !localidades[i].isEmpty)
			{
				localidades[i].isEmpty = 1;
				retorno = 0;

				for (int j = 0 ; j < lenClientes ; j++)
				{
					if (listaClientes[j].city == idLocalidad && !listaClientes[j].isEmpty)
					{
						BajaClienteV2(listaClientes, lenClientes, listaPedidos, lenPedidos, listaClientes[j].id);
					}
				}

			}
		}
	}

	return retorno;
}
