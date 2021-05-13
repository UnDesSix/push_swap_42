_BOLDMAGENTA	=	\033[1;94m
_RESET			=	\033[0m

all:
		@ echo "$(_BOLDMAGENTA)LIBTF : $(_RESET)"
		@ (cd libft; make --no-print-directory all)
		@ echo "\n$(_BOLDMAGENTA)CHECKER PROG : $(_RESET)"
		@ (cd checker_prog; make --no-print-directory all)
		@ echo "\n$(_BOLDMAGENTA)PUSH SWAP PROG : $(_RESET)"
		@ (cd push_swap_prog; make --no-print-directory all)

clean:
		@ echo "$(_BOLDMAGENTA)LIBTF : $(_RESET)"
		@ (cd libft; make --no-print-directory clean)
		@ echo "\n$(_BOLDMAGENTA)CHECKER PROG : $(_RESET)"
		@ (cd checker_prog; make --no-print-directory clean)
		@ echo "\n$(_BOLDMAGENTA)PUSH SWAP PROG : $(_RESET)"
		@ (cd push_swap_prog; make --no-print-directory clean)

fclean:
		@ echo "$(_BOLDMAGENTA)LIBTF : $(_RESET)"
		@ (cd libft; make --no-print-directory fclean)
		@ echo "\n$(_BOLDMAGENTA)CHECKER PROG : $(_RESET)"
		@ (cd checker_prog; make --no-print-directory fclean)
		@ echo "\n$(_BOLDMAGENTA)PUSH SWAP PROG : $(_RESET)"
		@ (cd push_swap_prog; make --no-print-directory fclean)

re:
		@ echo "$(_BOLDMAGENTA)LIBTF : $(_RESET)"
		@ (cd libft; make --no-print-directory re)
		@ echo "\n$(_BOLDMAGENTA)CHECKER PROG : $(_RESET)"
		@ (cd checker_prog; make --no-print-directory re)
		@ echo "\n$(_BOLDMAGENTA)PUSH SWAP PROG : $(_RESET)"
		@ (cd push_swap_prog; make --no-print-directory re)

.PHONY:	all clean fclean re
