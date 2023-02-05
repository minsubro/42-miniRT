/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:54:37 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/05 12:55:32 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

#define CHECK_ARGC "Check aruguments.\n Only support one parameter which ends \'.rt\' extension"

void	print_error_with_exit(char *msg);

#endif