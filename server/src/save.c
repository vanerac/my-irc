/*
** EPITECH PROJECT, 2021
** save
** File description:
** save
*/

#include <dlfcn.h>
#include "logging_server.h"
#include <sys/socket.h>
#include <sys/select.h>
#include <unistd.h>
#include <file_parser.h>
#include <signal.h>
#include <fcntl.h>
#include "commands.h"
#include "struct.h"
#include "sockets.h"
#include "handles.h"
#include "list.h"

void load(t_global *global)
{
    int team_fd = open("./teams.save", O_RDONLY, 0644);
    int users_fd = open("./users.save", O_RDONLY, 0644);
    int dm_fd = open("./dms.save", O_RDONLY, 0644);

    if (team_fd > 0)
        global->teams = parse_file(team_fd);
    if (users_fd > 0)
        global->all_user = parse_file(users_fd);
    if (dm_fd > 0)
        global->private_message = parse_file(dm_fd);
}

void save(t_global *data, bool write)
{
    static t_global *data_save = NULL;
    int team_fd = open("./teams.save", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    int users_fd = open("./users.save", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    int dm_fd = open("./dms.save", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (!write) {
        data_save = data;
        return;
    }
    for (list_t *l = data_save->teams; l; l = l->next)
        write_structure(team_fd, l->data, 5);
    close(team_fd);
    for (list_t *l = data_save->all_user; l; l = l->next)
        write_structure(users_fd, l->data, 1);
    close(users_fd);
    for (list_t *l = data_save->private_message; l; l = l->next)
        write_structure(dm_fd, l->data, 1);
    close(dm_fd);
}

void sig_save(int blc)
{
    (void) blc;
    printf("%s\n", "program killed by sig");
    save(NULL, true);
    exit(0);
}
