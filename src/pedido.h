#ifndef PEDIDO_H_
#define PEDIDO_H_

typedef struct
{
	int idPedido;
	float kilosTotales;
	int idCliente;
	int estado;
	float HDPE;
	float LDPE;
	float PP;
	int isEmpty;
}ePedido;

#define PENDIENTE 1
#define COMPLETADO 2

/// @fn int InicializarListaPedidos(eCliente[], int)
/// @brief Inicializa una lista de pedidos indicando que todas las posiciones estas vacias
///
/// @param lista Lista de pedidos a inicializar
/// @param len Largo de la lista de pedidos a inicializar
/// @return -1 por lista nula/rango invalido, 0 si se pudo inicializar
int InicializarListaPedidos(ePedido lista[], int len);

/// @fn int NuevoPedido(ePedido[], int, int)
/// @brief Da de alta un nuevo pedido para un cliente
///
/// @param listaPedidos Lista de pedidos donde se hara la carga
/// @param len Largo de la lista de pedidos donde se hara la carga
/// @param idCliente ID del cliente del cual se hara el pedido
/// @return -2 por lista nula/largo invalido, -1 si la lista esta llena, 0 si se hizo la carga
int NuevoPedido(ePedido listaPedidos[], int len, int idCliente);
//void MostrarPedido(ePedido pedido);
//int MostrarListaPedidos(ePedido listaPedidos[], int len);

/// @fn int MostrarListaPedidosPendientes(ePedido[], int)
/// @brief Muestra pedidos en estado pendiente
///
/// @param listaPedidos Lista de pedidos a verificar
/// @param len Largo de la lista de pedidos a verificar
/// @return -1 por lista nual/largo invalido, 0 si se pudo mostrar
int MostrarListaPedidosPendientes(ePedido listaPedidos[], int len);

/// @fn int HayPedido(ePedido[], int)
/// @brief Informa si hay al menos 1 pedido en la lista
///
/// @param lista Lista de pedidos a verificar
/// @param len Largo de la lista de pedidos a verificar
/// @return 0 por lista nula/largo invalido o si no hay ningun pedido, 1 si hay al menos un pedido
int HayPedido(ePedido lista[], int len);

/// @fn int ProcesarPedido(ePedido[], int, int)
/// @brief Procesa un pedido indicando que cantidad de los kilos totales corresponde a HDPE, LDPE y PP y valida que sean numero validos
///
/// @param listaPedidos Lista de pedidos donde se va a procesar el pedido
/// @param len Largo de la lista de pedidos donde se va a procesar el pedido
/// @param idPedido ID del pedido a procesar
/// @return -2 por lista nula/largo invalido, -1 si el pedido ya estaba procesado, 0 si se pudo procesar
int ProcesarPedido(ePedido listaPedidos[], int len, int idPedido);

/// @fn int BuscarPosicionPedidosPorID(ePedido[], int, int)
/// @brief Busca y retorna la posicion de un pedido segun un ID
///
/// @param lista Lista de pedidos donde se hara la busqueda
/// @param len Largo de la lista de pedidos donde se hara la busqueda
/// @param id ID a buscar la posicion
/// @return -1 por lista nula/largo invalido o si no se encontro, sino la posicion en el array del pedido
int BuscarPosicionPedidosPorID(ePedido lista[], int len, int id);

/// @fn int HayPedidoCompletado(ePedido[], int)
/// @brief Informa si hay al menos 1 pedido completado en la lista
///
/// @param lista Lista de pedidos a verificar
/// @param len Largo de la lista de pedidos a verificar
/// @return 0 por lista nula/largo invalido o si no hay ningun pedido, 1 si hay al menos un pedido completado
int HayPedidoCompletado(ePedido lista[], int len);

/// @fn int HayPedidoPendiente(ePedido[], int)
/// @brief Informa si hay al menos 1 pedido pendiente en la lista
///
/// @param lista Lista de pedidos a verificar
/// @param len Largo de la lista de pedidos a verificar
/// @return 0 por lista nula/largo invalido o si no hay ningun pedido, 1 si hay al menos un pedido pendiente
int HayPedidoPendiente(ePedido lista[], int len);

/// @fn int BajaPedidoPorIDCliente(ePedido[], int, int)
/// @brief Da de baja todos los pedidos de un cliente indicado por id
///
/// @param lista Lista de pedidos donde se daran de baja los pedidos
/// @param len Largo de la lista de pedidos donde se daran de baja los pedidos
/// @param idCliente ID del cliente del que se daran de baja los pedidos
/// @return -1 Por lista nula/largo invalido o si no se hizo ninguna baja, 0 si de dio de baja al menos 1 pedido
int BajaPedidoPorIDCliente (ePedido lista[], int len, int idCliente);


#endif
