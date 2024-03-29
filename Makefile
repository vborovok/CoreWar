# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/01 12:47:43 by fmasha-h          #+#    #+#              #
#    Updated: 2019/12/01 15:57:37 by fmasha-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM	= asm/asm

COREWAR = vm/corewar

BINARIES = binaries

all: $(BINARIES) $(ASM) $(COREWAR)

$(BINARIES):
	@mkdir -p binaries

$(ASM):
	@make -C asm
	@cp asm/asm binaries/

$(COREWAR):
	@make -C vm
	@cp vm/corewar binaries/

clean:
	@make clean -C asm
	@make clean -C vm
	@rm -rf binaries

fclean: clean
	@make fclean -C asm
	@make fclean -C vm

re: fclean all
