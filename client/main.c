/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** main
*/

#include <string.h>
#include "sockets.h"
#include "client.h"

char **get_all_func(void)
{
    char *all[] = {"client_event_logged_in", "client_event_logged_out",
    "client_event_private_message_received", "client_event_team_created",
    "client_event_thread_reply_received", "client_event_thread_created",
    "client_private_message_print_messages", "client_print_subscribed",
    "client_event_channel_created", "client_channel_print_threads",
    "client_team_print_channels", "client_print_teams", "client_print_user",
    "client_error_unknown_channel", "client_thread_print_replies",
    "client_error_unknown_team", "client_error_unknown_thread",
    "client_error_unknown_user", "client_print_team", "client_print_thread",
    "client_error_already_exist", "client_print_channel", "client_print_users",
    "client_print_channel_created", "client_error_unauthorized",
    "client_print_thread_created", "client_print_team_created",
    "client_print_reply_created", "client_print_unsubscribed"};
    char **ret = malloc(sizeof(char *) * 29);

    for (int i = 0; i < 29; i++) {
        if (!ret || (ret[i] = strdup(all[i])) == NULL)
            return NULL;
    }
    return ret;
}

lib_func_client_t *load_client_lib(char *handle)
{
    char **all_func = get_all_func();
    lib_func_client_t *lib = malloc(sizeof(lib_func_client_t) * 29);

    if (!lib)
        return NULL;
    for (int i = 0; i < 29; i++) {
        lib[i].name = all_func[i];
        lib[i].func = dlsym(handle, lib[i].name);
        if (!lib[i].func)
            return NULL;
    }
    return lib;
}

int main(int ac, char **ag)
{
    char *handle = dlopen("./libs/myteams/libmyteams.so", RTLD_LAZY);
    struct data *var = malloc(sizeof(struct data));

    if (ac < 2 || !handle || !var)
        return 84;
    lib_func_client_t *lib_client = load_client_lib(handle);
    if (!lib_client)
        return 84;

    var->server_fd = client_create(atoi(ag[1]), "127.0.0.1");
    var->buffer_client = calloc(sizeof(char), 200);
    var->buffer_server = calloc(sizeof(char), 200);

    message_info_t ok;

    while (1) {
        if (read_message(&ok, var->server_fd)){
            printf("buffer server => %s\n", ok.args);
            server_handler(&ok, lib_client);
            memset(var->buffer_server, 0, 200);
            printf("SERVER\n");
        }

        if (read(0, var->buffer_client, 200) != 0){
            printf("buffer client => %s\n", var->buffer_client);
            send_message(var->server_fd, var->buffer_client, COMMAND, INVALID);
            memset(var->buffer_client, 0, 200);
            printf("CLIENT\n");
        }
    }
    dlclose(var->handle);
}