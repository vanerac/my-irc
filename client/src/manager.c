/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-corentin.mas
** File description:
** manager
*/

#include "client.h"

int search_command(char *cmd[], char *handle_cmd)
{
    int return_value = -1;

    for (int i = 0; i < 29; i++){
        if (strcmp(handle_cmd, cmd[i]) == 0)
            return_value = i;
    }
    return (return_value);
}

void server_handler(struct data *var)
{
    var->handle = dlopen("./libs/myteams/libmyteams.so", RTLD_LAZY);
    char *cmd[] = {"200", "201", "202", "203", "204", "205", "206", "207",
                    "208", "209", "210", "211", "212", "213", "214", "215",
                    "216", "217", "218", "219", "220", "221", "222", "223",
                    "224", "225", "226", "227", "228"};

    var->splitted_cmd = str_to_word_array(var->buffer_server, ' ');
    int to_point = search_command(cmd, var->splitted_cmd[0]);
    
    if (to_point == -1){
        printf("Unkwown Command\n");
        return;
    } else {
        void (*fun_ptr_arr[])(struct data *) = {login_ok_200, logout_ok_201,
        dm_received_202, thread_reply_203, event_team_created_204,
        event_channel_created_205, event_thread_created_206, print_users_207,
        print_teams_208, print_channels_209, print_threads_210,
        print_replies_211, print_dm_212, unknown_team_213, unknown_channel_214,
        unknown_thread_215, unknown_user_216, no_auth_217, already_exist_218, 
        info_user_219, info_team_220, info_channel_221, info_thread_222,
        team_created_only_for_creator_223, channel_created_only_for_creator_224,
        thread_created_only_for_creator_225, reply_created_only_for_creator_226,
        subscribed_created_only_for_creator_227,
        unsubscribed_created_only_for_creator_228};

        (*fun_ptr_arr[to_point])(var);
    }
}