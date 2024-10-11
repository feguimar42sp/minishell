/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 00:29:23 by fernando          #+#    #+#             */
/*   Updated: 2024/10/11 00:55:38 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

void    parse_token(char **split_line, int i, t_commandblock *current_block)
{
    if (split_line || i || current_block)
        return ;
    // essa função tem os seguintes tratamentos:
    // caso seja $ somar a variável de ambiente expandida a words
    // caso seja heredoc armazenar o string fim do heredoc no local adequado do bloco
    // caso seja | (pipe) rodar a função add_command_block()
    // caso seja redirecionamento (> >> ou <) confirmar que a próxima posição é arquivo válido
    // e armazenar token seguido do arquivo na posição adequda, caso já haja um apagar e registrar de novo
}