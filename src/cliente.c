#include "cliente.h"
#include "inputs.h"

/// @fn int NewID()
/// @brief Genera un id unico
///
/// @return ID Unico
static int NewID();

/// @fn void MostraCliente(eCliente, eLocalidad[], int)
/// @brief Muestra un cliente: Id, Nombre, CUIT, Direccion y localidad
///
/// @param cliente Cliente a mostrar
/// @param localidades Lista de localidades disponibles para mostrar
/// @param lenLocalidades Largo de la lista de localidades disponibles para mostrar
static void MostraCliente(eCliente cliente, eLocalidad localidades[], int lenLocalidades);

int AltaCliente(eCliente listaClientes[], int len, eLocalidad localidades[], int lenLocalidades)
{
	int retorno = -2;
	int localidad;

	if(listaClientes != NULL && len > 1 && localidades != NULL && lenLocalidades > 0)
	{
		for(int i = 0 ; i < len ; i++)
		{
			retorno = -1;

			if(listaClientes[i].isEmpty)
			{
				PedirCadena(listaClientes[i].name, sizeof(listaClientes[i].name), "\nIngrese el nombre de la empresa: ", "\nError");
				listaClientes[i].cuit = PedirCUIL_CUIT("\nIngrese el CUIT: ", "\nError, CUIT INVALIDO");
				PedirCadena(listaClientes[i].adress, sizeof(listaClientes[i].adress), "\nIngrese la dirección: ", "\nError");

				localidad = PedirLocalidad(localidades, lenLocalidades, "\nIngrese el numero de una localidad de la lista: ", "\nError, ingrese un numero de la lista: ");

				if (localidad == -1 || localidad == -2)
				{
					retorno = -3;
					break;
				}

				listaClientes[i].city = localidad;
				listaClientes[i].isEmpty = 0;
				listaClientes[i].id = NewID();
				retorno = listaClientes[i].id;
				break;
			}
		}
	}

	return retorno;
}

int MostrarListaClientes(eCliente listaClientes[], int len, eLocalidad localidades[], int lenLocalidades)
{
	int retorno = -1;
	int flagPrimero = 1;

	if(listaClientes != NULL && len > 1)
	{
		for(int i = 0 ; i < len ; i++)
		{
			if(!listaClientes[i].isEmpty)
			{
				if(flagPrimero)
				{
					printf("\nID   NOMBRE           CUIT           DIRECCION        LOCALIDAD");
				}

				MostraCliente(listaClientes[i],localidades, lenLocalidades);
				flagPrimero = 0;
				retorno = 0;
			}
		}
	}

	return retorno;
}

static void MostraCliente(eCliente cliente, eLocalidad localidades[], int lenLocalidades)
{
	for(int i = 0 ; i < lenLocalidades ; i++)
	{
		if (cliente.city == localidades[i].id)
		{
			printf("\n%-4d %-16s %-14.0lf %-16s %-16s",cliente.id, cliente.name,cliente.cuit,cliente.adress,localidades[i].descripcion);
		}
	}
}

int ModificarCliente(eCliente lista[], int len, eLocalidad localidades[], int lenLocalidades, int id)
{
	int retorno = -1;
	int localidad;
	char buffer[51];

	if(lista != NULL && len > 1)
	{
		for(int i = 0 ; i < len ; i++)
		{
			if(lista[i].id == id && !lista[i].isEmpty)
			{
				PedirCadena(buffer, sizeof(buffer), "\nIngrese la nueva direccion: ", "\nError: ");
				localidad = PedirLocalidad(localidades, lenLocalidades, "\nIngrese el numero de una localidad de la lista: ", "\nError, ingrese un numero de la lista: ");

				if (localidad == -1 || localidad == -2)
				{
					retorno = -2;
					break;
				}

				strcpy(lista[i].adress,buffer);
				lista[i].city = localidad;

				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int BuscarPosicionClientePorID(eCliente lista[], int len, int id)
{
	int retorno = -1;

	if(lista != NULL && len > 1)
	{
		for(int i = 0 ; i < len ; i++)
		{
			if(lista[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int InicializarListaClientes(eCliente lista[], int len)
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

int BajaCliente(eCliente lista[], int len, int id)
{
	int retorno = -1;

	if(lista != NULL && len > 1)
	{
		for(int i = 0 ; i < len ; i++)
		{
			if(lista[i].id == id && !lista[i].isEmpty)
			{
				lista[i].isEmpty = 1;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int HayCliente(eCliente lista[], int len)
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

static int NewID()
{
	static int id = 0;
	id++;
	return id;
}
