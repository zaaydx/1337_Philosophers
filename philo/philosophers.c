
#include "philosophers.h"

int main(int argc, char **argv)
{
    t_arguments     *args;

    args = (t_arguments *)malloc(sizeof(t_arguments));
    if (!check_input(argc, argv, args))
    {
        free(args);
        return (1);
    }
    return (0);
}