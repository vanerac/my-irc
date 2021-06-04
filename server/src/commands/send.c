/*
** EPITECH PROJECT, 2021
** C
** File description:
** send.c file
*/

#include <commands.h>

static bool find_dms(void *it, void *data)
{
    return (!uuid_compare(((t_dm *) it)->user_first, *((uuid **) data)[0]) ||
        !uuid_compare(((t_dm *) it)->user_first, *((uuid **) data)[1])) &&
        (!uuid_compare(((t_dm *) it)->user_second, *((uuid **) data)[0]) ||
            !uuid_compare(((t_dm *) it)->user_second, *((uuid **) data)[1]));
}

static t_dm *create_dm(t_global *global, session_t *session, uuid target)
{
    t_dm *ret = malloc(sizeof(t_dm));
    uuid_copy(ret->user_first, session->user_data->uid);
    uuid_copy(ret->user_second, target);
    ret->type = DM;
    if (!global->private_message)
        global->private_message = node_list_create(ret);
    else
        node_append_data(global->private_message, ret);
    return ret;
}

static t_messages *init_message(t_user  *author, void *destination, char
*body)
{
    t_messages *ret = malloc(sizeof(t_messages));
    ret->type = MESSAGE;
    uuid_generate(ret->uid);
    ret->author = author;
    ret->destination = destination;
    ret->body = body;
    ret->title = NULL;
    time(&ret->created_at);
    ret->replies = NULL;
    ret->m_type = M_DM;
    return ret;
}

void command_send(t_global *global, session_t *session, char **args)
{
    uuid target;
    char *message = args[1];
    uuid_parse(args[0], target);
    uuid *uuids[2] = {&session->user_data->uid, &target};

    if (!node_find_fn(global->all_user, &find_by_uuid,
        args[0])) {
        return; // todo user doesnt exist
    }

    list_t *dms = node_find_fn(global->private_message, &find_dms, uuids);
    t_dm *dm;
    if (!dms)
        dm = create_dm(global, session, target);
    else
        dm = dms->data;
    t_messages *ret = init_message(session->user_data, dm, message);
    if (!dm->messages)
        dm->messages = node_list_create(ret);
    else
        node_append_data(dm->messages, ret);

    // todo write to client OK
    list_t *target_session = node_find_fn(global->sessions, &find_by_uuid,
        target);
    if (!target_session) {
        // cant find session
        return;
    }

}