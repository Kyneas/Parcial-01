#ifndef LOCALIDADES_H_
#define LOCALIDADES_H_

typedef struct
{
	int id;
	char descripcion[51];
	int isEmpty;

}eLocalidad;

int ModificarLocalidad (eLocalidad lista[], int len, int id);

/// @fn int InicializarListaLocalidades(eLocalidad[], int)
/// @brief Inicializa una lista de localidades indicando que todas las posiciones estas vacias
///
/// @param lista Lista de localidades a inicializar
/// @param len Largo de la lista de localidades a inicializar
/// @return -1 por lista nula/rango invalido, 0 si se pudo inicializar
int InicializarListaLocalidades(eLocalidad lista[], int len);

/// @fn int BuscarPosicionLocalidadesPorID(eLocalidad[], int, int)
/// @brief Busca la posicion de una localidad buscando el ID
///
/// @param localidades Lista de localidades donde se hara la busqueda
/// @param len Largo de la lista de localidades donde se hara la busqueda
/// @param id ID a buscar
/// @return -1 por lista nula/largo invalido o si no se encontro, sino la posicion de la localidad en la lista
int BuscarPosicionLocalidadesPorID(eLocalidad localidades[], int len, int id);

/// @fn int MostrarLocalidadesConIndice(eLocalidad[], int)
/// @brief Muestra todas las localidades activas con un contador a su izquierda y el numero 0 al principo
///
/// @param localidades Lista de localidades a mostrar
/// @param len Largo de la lista de localidades a mostrar
/// @return -1 por lista nula/largo invalido o si no se pudo mostrar ninguna localidad, 0 si mostro al menos 1
int MostrarLocalidadesConIndice(eLocalidad localidades[], int len);

/// @fn int DevolverIDLocalidadContandoActivas(eLocalidad[], int, int)
/// @brief Retorna el ID de una localidad teniendo en cuenta su posicion contando solo las posiciones activas
///
/// @param localidades Lista de localidades donde se buscara el ID
/// @param len Largo de la lista de localidades donde se buscara el ID
/// @param posicionActiva Indice activo donde se debera buscar el ID
/// @return -1 por lista nula/largo invalido o si no se encontro, o el ID de la localidad buscada
int DevolverIDLocalidadContandoActivas (eLocalidad localidades[], int len, int posicionActiva);

/// @fn int PedirLocalidad(eLocalidad[], int, char[], char[])
/// @brief Pide al usuario que ingrese una localidad luego de mostrar una lista con todas junto a un indice correspondiente
///
/// @param localidades Lista de localidades a mostrar
/// @param len Largo de la lista de localidades a mostrar
/// @param mensaje Mensaje que se muestra al pedir una localidad
/// @param mensajeError Mensaje que se muestra en caso de ingresar un caracter invalido o un numero que no esta en la lista
/// @return -1 en caso de lista nula/largo invalido, -2 si el usuario cancela, sino el ID de la localidad solicitada
int PedirLocalidad (eLocalidad localidades[], int len, char mensaje[], char mensajeError[]);

/// @fn int AltaLocalidad(eLocalidad[], int)
/// @brief Da de alta una nueva localidad solicitando el nombre al usuario y asignandole un ID automatico unico
///
/// @param localidades Lista donde se cargara la nueva localidad
/// @param len Largo de la lista donde se cargara la nueva localidad
/// @return -1 por lista nula/largo invalido o si no hay espacio en la lista, 0 si se pudo realizar la carga
int AltaLocalidad(eLocalidad localidades[], int len);

/// @fn int HayLocalidad(eLocalidad[], int)
/// @brief Informa si hay al menos una localidad cargada en la lista
///
/// @param localidades
/// @param len
/// @return
int HayLocalidad (eLocalidad localidades[], int len);

#endif
