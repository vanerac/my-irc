/*
** EPITECH PROJECT, 2021
** C
** File description:
** server.c file
*/

#include <dlfcn.h>
#include "struct.h"
#include "sockets.h"
#include "handles.h"
#include "list.h"

void set_ports(fd_set *rfds, list_t *sessions)
{
    FD_ZERO(rfds);
    for (list_t *i = sessions; i; i = i->next) {
        FD_SET(((session_t *) i->data)->socket, rfds);
    }
}

static bool find_session_by_fd(void *iterator, void *value)
{
    return ((session_t *) iterator)->socket == *(int *) value;
}

int listen_updates(int server_socket, list_t *sessions, t_global *global,
    fd_set *rfds
)
{
    set_ports(rfds, sessions);
    FD_SET(server_socket, rfds);
    if (select(FD_SETSIZE, rfds, NULL, NULL, NULL) == -1)
        return 84;
    int status = 0;
    for (int i = 0; i < FD_SETSIZE && status == 0; ++i)
        if (FD_ISSET(i, rfds) && i != server_socket) {
            list_t *n = node_find_fn(sessions, &find_session_by_fd, &i);
            status = handle_command(global, n ? n->data : NULL);
        } else if (FD_ISSET(i, rfds) && i == server_socket)
            handle_connections(sessions, server_socket);
    return 0;
}

libfunctions_t *init_lib_func(void *handle)
{
    libfunctions_t *ptr_func = malloc(sizeof(libfunctions_t) * 11);

    if (!ptr_func)
        return NULL;
    ptr_func[0].name = "server_event_team_created";
    ptr_func[0].func = dlsym(handle, ptr_func[0].name);
    ptr_func[1].name = "server_event_channel_created";
    ptr_func[1].func = dlsym(handle, ptr_func[1].name);
    ptr_func[2].name = "server_event_thread_created";
    ptr_func[2].func = dlsym(handle, ptr_func[2].name);
    ptr_func[3].name = "server_event_thread_new_reply";
    ptr_func[3].func = dlsym(handle, ptr_func[3].name);
    ptr_func[4].name = "server_event_user_subscribed";
    ptr_func[4].func = dlsym(handle, ptr_func[4].name);
    ptr_func[5].name = "server_event_user_unsubscribed";
    ptr_func[5].func = dlsym(handle, ptr_func[5].name);
    ptr_func[6].name = "server_event_user_created";
    ptr_func[6].func = dlsym(handle, ptr_func[6].name);
    ptr_func[7].name = "server_event_user_loaded";
    ptr_func[7].func = dlsym(handle, ptr_func[7].name);
    ptr_func[8].name = "server_event_user_logged_in";
    ptr_func[8].func = dlsym(handle, ptr_func[8].name);
    ptr_func[9].name = "server_event_user_logged_out";
    ptr_func[9].func = dlsym(handle, ptr_func[9].name);
    ptr_func[10].name = "server_event_private_message_sent";
    ptr_func[10].func = dlsym(handle, ptr_func[10].name);
    return ptr_func;
}

int myteams_server(int server_socket)
{
    fd_set rfds;
    FD_ZERO(&rfds);
    void *handle = dlopen("libs/myteams/libmyteams.so", RTLD_LAZY);
    //    int server_socket = server_create(port);

    int *data = malloc(sizeof(int));
    *data = server_socket;
    list_t *sessions = node_list_create(data);
    t_global global = {.all_user = NULL, .private_message = NULL, .teams =
    NULL, .sessions = sessions};
    if (!sessions || !handle)
        return 84;
    global.lib_func = init_lib_func(handle);
    if (server_socket < 0 || !global.lib_func)
        return 84;
    int status = 0;
    while (status == 0)
        status = listen_updates(server_socket, sessions, &global, &rfds);
    dlclose(handle);
    return 0;
}