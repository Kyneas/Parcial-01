#ifndef NEXO_H_
#define NEXO_H_

typedef struct
{
	int id;
	int contador;
	int acumulador;

}eAuxiliar;

int ClientesConMasPendientes (eCliente listaClientes[], int len,ePedido listaPedidos[], int lenPedidos);
int ClientesConMasCompletados (eCliente listaClientes[], int len,ePedido listaPedidos[], int lenPedidos);

/// @fn int MostrarClientesConPedidosPendientes(eCliente[], int, ePedido[], int, eLocalidad[], int)
/// @brief Muestra una lista con todos los clientes y la cantidad de pedidos pendientes que tienen
///
/// @param listaClientes Lista de clientes a mostrar
/// @param len Largo de la lista de clientes a mostrar
/// @param listaPedidos Lista donde se buscaran los pedidos pendientes
/// @param lenPedidos Largo de la lista donde se buscaran los pedidos pendientes
/// @param localidades Lista de localidades cargaadas
/// @param lenLocalidades Largo de la lista de localidades cargaadas
/// @return -1 en caso de lista nula/largo invalido o si no se pudo mostrar nada, 0 si se muestra al menos 1 cliente
int MostrarClientesConPedidosPendientes(eCliente listaClientes[], int len,ePedido listaPedidos[], int lenPedidos, eLocalidad localidades[], int lenLocalidades);

/// @fn int MostrarPedidosPendientesYDatosCliente(eCliente[], int, ePedido[], int, eLocalidad[], int)
/// @brief Muestra todos los pedidos pendientes y los datos del cliente que lo solicito
///
/// @param listaClientes Lista de clientes a verificar y mostrar
/// @param len Largo de la lista de clientes a verificar y mostrar
/// @param listaPedidos Lista de pedidos donde se buscaran los pedidos pendientes
/// @param lenPedidos Largo de la lista de pedidos donde se buscaran los pedidos pendientes
/// @param localidades Lista de localidades
/// @param lenLocalidades Largo de la lista de localidades
/// @return -1 en caso de lista nula/largo invalido o si no encontro ningun pendiente, 0 si pudo mostrar 1 pedido pendiente
int MostrarPedidosPendientesYDatosCliente(eCliente listaClientes[], int len,ePedido listaPedidos[], int lenPedidos, eLocalidad localidades[], int lenLocalidades);

/// @fn int MostrarPedidosCompletadosYDatosCliente(eCliente[], int, ePedido[], int, eLocalidad[], int)
/// @brief Muestra todos los pedidos completados y los datos del cliente que lo solicito
///
/// @param listaClientes Lista de clientes a verificar y mostrar
/// @param len Largo de la lista de clientes a verificar y mostrar
/// @param listaPedidos Lista de pedidos donde se buscaran los pedidos completados
/// @param lenPedidos Largo de la lista de pedidos donde se buscaran los pedidos completados
/// @param localidades Lista de localidades
/// @param lenLocalidades Largo de la lista de localidades
/// @return -1 en caso de lista nula/largo invalido o si no encontro ningun pendiente, 0 si pudo mostrar 1 pedido completado
int MostrarPedidosCompletadosYDatosCliente(eCliente listaClientes[], int len,ePedido listaPedidos[], int lenPedidos, eLocalidad localidades[], int lenLocalidades);

/// @fn int BuscarPendientesParaLocalidad(eCliente[], int, ePedido[], int, eLocalidad[], int, int)
/// @brief Busca y retorna la cantidad de pedidos pendientes que tiene una localidad indicada por el usuario
///
/// @param listaClientes Lista de clientes a analizar para buscar los pendientes
/// @param len Largo de la lista de clientes a analizar para buscar los pendientes
/// @param listaPedidos Lista de pedidos donde se buscaran los pendientes
/// @param lenPedidos Largo de la lista de pedidos donde se buscaran los pendientes
/// @param localidades Lista de localidades donde se buscara la correspondencia con el ID brindado como parametro
/// @param lenLocalidades Largo de la lista de localidades donde se buscara la correspondencia con el ID brindado como parametro
/// @param idLocalidad ID de la localidad a buscar los pendientes
/// @return -2 en caso de lista nula/largo invalido, -1 si no encontro pendientes para esa localidad, sino la cantidad de pedidos de esa localidad
int BuscarPendientesParaLocalidad(eCliente listaClientes[], int len,ePedido listaPedidos[], int lenPedidos,eLocalidad localidades[], int lenLocalidades,int  localidad);

/// @fn float CalcularPromedioPP(eCliente[], int, ePedido[], int)
/// @brief Calcula la cantidad promedio de PP que tienen todos los clientes;
///
/// @param listaClientes Lista de clientes a analizar
/// @param len Largo de la lista de clientes a analizar
/// @param listaPedidos Lista de pedidos donde se buscara la cantidad total de PP
/// @param lenPedidos Largo de la lista de pedidos donde se buscara la cantidad total de PP
/// @return -1 de lista nula/largo invalido o si no hay nada de PP, sino la cantidad promedio de PP
float CalcularPromedioPP(eCliente listaClientes[], int len,ePedido listaPedidos[], int lenPedidos);

/// @fn int BajaClienteV2(eCliente[], int, ePedido[], int, int)
/// @brief Da de baja el cliente correspondiente a un ID y todos los pedidos que tenga cargados
///
/// @param lista Lista de clientes donde se hara la baja
/// @param len Largo de la lista de clientes donde se hara la baja
/// @param listaPedidos Lista de pedidos a verificar para dar de baja
/// @param lenPedidos Largo de la lista de pedidos a verificar para dar de baja
/// @param id ID del cliente a dar de baja
/// @return -1 por lista nula/ largo invalido o si no encontro el id, 0 si se pudo hacer la baja
int BajaClienteV2(eCliente lista[], int len,ePedido listaPedidos[], int lenPedidos, int id);

/// @fn int BajaLocalidad(eCliente[], int, ePedido[], int, eLocalidad[], int, int)
/// @brief Da de baja una localidad y en consecuencia todos los clientes y tambien los pedidos de esos clientes
///
/// @param listaClientes Lista de cliente a analizar para la baja
/// @param lenClientes Largo de la lista de cliente a analizar para la baja
/// @param listaPedidos Lista de pedidos a analizar para la baja
/// @param lenPedidos Largo de la lista de pedidos a analizar para la baja
/// @param localidades Lista de localidades donde se buscara la correspondiente para la baja
/// @param lenLocalidades Largo de la lista de localidades donde se buscara la correspondiente para la baja
/// @param idLocalidad ID de la localidad a dar de baja
/// @return -1 por lista nula/largo invalido o si no se encontro la localidad, 0 si la baja se realizo correctamente
int BajaLocalidad(eCliente listaClientes[], int lenClientes,ePedido listaPedidos[], int lenPedidos,eLocalidad localidades[], int lenLocalidades,int  idLocalidad);

#endif
