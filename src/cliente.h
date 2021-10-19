#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "localidades.h"

typedef struct
{
	int id;
	char name[51];
	double cuit;
	char adress[51];
	int city;
	int isEmpty;
}eCliente;

/// @fn int AltaCliente(eCliente[], int, eLocalidad[], int)
/// @brief  Da de alta un nuevo cliente solicitando todos las datos al usuario
///
/// @param listaClientes Lista de cliente donde se realizara la carga
/// @param len largo de la lista de cliente donde se realizara la carga
/// @param localidades Localidades disponibles para hacer la carga
/// @param lenLocalidades lista de localidades disponibles para hacer la carga
/// @return -2 por listado nulos o largos invalidos, -1 por falta de espacio en la lista, -3 si el usuario no carga localidad, id del cliente si la carga es correcta
int AltaCliente(eCliente listaClientes[], int len, eLocalidad localidades[], int lenLocalidades);

/// @fn int MostrarListaClientes(eCliente[], int, eLocalidad[], int)
/// @brief Muestra Id, nombre, CUIT, direccion y localidad de los clientes activos
///
/// @param listaClientes Lista de clientes a mostrar
/// @param len Largo de la lista de clientes a mostrar
/// @param localidades Lista de localidades disponibles para mostrar
/// @param lenLocalidades Largo de la lista de localidades disponibles para mostrar
/// @return -1 por listas nulas o largos invalidos o no se mostro nada, 0 si se llego a mostrar 1 cliente
int MostrarListaClientes(eCliente listaClientes[], int len, eLocalidad localidades[], int lenLocalidades);

/// @fn int ModificarCliente(eCliente[], int, eLocalidad[], int, int)
/// @brief Modifica el cliente que se indico por medio de un ID
///
/// @param lista Lista donde de encuentra el cliente a modificar
/// @param len Largo de la lista donde de encuentra el cliente a modificar
/// @param localidades Lista de localidades disponibles
/// @param lenLocalidades Largo de la lista de lista de localidades disponibles
/// @param id ID del cliente a modificar
/// @return -1 por listas nulas/largos invalidos o si no se realizo la carga, 0 si se pudo modificar
int ModificarCliente(eCliente lista[], int len, eLocalidad localidades[], int lenLocalidades, int id);

/// @fn int BuscarPosicionClientePorID(eCliente[], int, int)
/// @brief Busca la posicion de un cliente en el vector
///
/// @param lista Lista de clientes a donde se realiza la busqueda
/// @param len Largo de la lista de clientes a donde se realiza la busqueda
/// @param id ID del cliente a buscar la posicion
/// @return -1 por lista nula/largo invalido o si no se encontro el cliente, sino la posicion del cliente
int BuscarPosicionClientePorID(eCliente lista[], int len, int id);

/// @fn int InicializarListaClientes(eCliente[], int)
/// @brief Inicializa una lista de clientes indicando que todas las posiciones estas vacias
///
/// @param lista Lista de clientes a inicializar
/// @param len Largo de la lista de clientes a inicializar
/// @return -1 por lista nula/rango invalido, 0 si se pudo inicializar
int InicializarListaClientes(eCliente lista[], int len);

/// @fn int BajaCliente(eCliente[], int, int)
/// @brief Da de baja el cliente indicado por id
///
/// @param lista Lista de clientes donde se encuentra el cliende a dar de baja
/// @param len Largo de la lista de clientes donde se encuentra el cliende a dar de baja
/// @param id ID del cliente a dar de baja
/// @return -1 por lista nula/largo invalido o si no existe el cliente, 0 si la baja se pudo realizar
int BajaCliente(eCliente lista[], int len, int id);

/// @fn int HayCliente(eCliente[], int)
/// @brief Indica si hay al menos 1 cliente cargados en la lista
///
/// @param lista Lista de clientes a verificar
/// @param len Largo de la lista de clientes a verificar
/// @return 0 por lista nula/largo invalido o si no hay clientes, 1 si hay clientes
int HayCliente(eCliente lista[], int len);

#endif
