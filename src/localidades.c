#include "inputs.h"

#include "localidades.h"

/// @fn int NewID()
/// @brief Genera un ID unico para las localidades
///
/// @return ID Unico
static int NewID();

/// @fn void MostrarLocalidadConIdice(eLocalidad, int)
/// @brief Muestra una localidad con un indice brindado por el usuario
///
/// @param localidad Localidad a mostrar
/// @param indice Indice correspondiente a la localidad
static void MostrarLocalidadConIdice(eLocalidad localidad, int indice);

int ModificarLocalidad (eLocalidad lista[], int len, int id)
{
	int retorno = -1;

	if (lista != NULL && len > 0)
	{
		for (int i = 0 ; i < len ; i++)
		{
			if (!lista[i].isEmpty && lista[i].id == id)
			{
				PedirCadena(lista[i].descripcion, sizeof(lista[i].descripcion), "\nIngrese el nuevo nombre para la localidad: ", "\nError: ");
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int InicializarListaLocalidades(eLocalidad lista[], int len)
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

int AltaLocalidad(eLocalidad localidades[], int len)
{
	int retorno = -1;

	if (localidades != NULL && len > 0)
	{
		for (int i = 0 ; i < len ; i++)
		{
			if (localidades[i].isEmpty)
			{
				PedirCadena(localidades[i].descripcion, sizeof(localidades[i].descripcion), "\nIngrese el nombre de la localidad", "\nError");
				localidades[i].isEmpty = 0;
				localidades[i].id = NewID();
				retorno = localidades[i].id;
				break;
			}
		}
	}

	return retorno;
}

int HayLocalidad (eLocalidad localidades[], int len)
{
	int retorno = 0;

	if (localidades != NULL && len > 0)
	{
		for (int i = 0 ; i < len ; i++)
		{
			if (!localidades[i].isEmpty)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

int MostrarLocalidadesConIndice(eLocalidad localidades[], int len)
{
	int retorno = -1;
	int contador = 0;
	int flag = 1;

	if (localidades != NULL && len > 0)
	{
		for (int i = 0 ; i < len ; i++)
		{
			if(!localidades[i].isEmpty)
			{
				if(flag)
				{
					printf("0. Cancelar");
				}
				flag = 0;
				contador++;
				MostrarLocalidadConIdice(localidades[i],contador);
				retorno = 0;

			}
		}
	}

	return retorno;
}

static void MostrarLocalidadConIdice(eLocalidad localidad, int indice)
{
	printf("\n%d.  %s",indice,localidad.descripcion);
}

int DevolverIDLocalidadContandoActivas (eLocalidad localidades[], int len, int posicionActiva)
{
	int retorno = -1;
	int contador = 0;

	for (int i = 0 ; i < len ; i++)
	{
		if (!localidades[i].isEmpty)
		{
			contador++;

			if (contador == posicionActiva)
			{
				retorno = localidades[i].id;
				break;
			}
		}
	}

	return retorno;
}

int BuscarPosicionLocalidadesPorID(eLocalidad localidades[], int len, int id)
{
	int retorno = -1;

	if(localidades != NULL && len > 0)
	{
		for(int i = 0 ; i < len ; i++)
		{
			if(!localidades[i].isEmpty && localidades[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int PedirLocalidad (eLocalidad localidades[], int len, char mensaje[], char mensajeError[])
{
	int retorno = -1;
	int localidad;

	if (localidades != NULL && len > 0)
	{
		MostrarLocalidadesConIndice(localidades, len);

		localidad = PedirEnteroPositivo(mensaje, mensajeError);

		while (DevolverIDLocalidadContandoActivas(localidades, len,localidad) == -1)
		{
			if (localidad == 0)
			{
				retorno = -2;
				break;
			}

			localidad = PedirEntero(mensajeError, mensajeError);
		}

		if (localidad != 0)
		{
			retorno = DevolverIDLocalidadContandoActivas(localidades, len,localidad);
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
