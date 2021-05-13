_BOLDMAGENTA=	\033[1;94m
_YELLOW		=	\033[38;5;184m
_GREEN		=	\033[38;5;46m
_RESET		=	\033[0m

all:
		@ echo "$(_BOLDMAGENTA)LIBTF : $(_RESET)"
		@ (cd libft; make --no-print-directory all)
		@ echo "\n$(_BOLDMAGENTA)CHECKER PROG : $(_RESET)"
		@ (cd checker_prog; make --no-print-directory all)

clean:
		@ echo "$(_BOLDMAGENTA)LIBTF : $(_RESET)"
		@ (cd libft; make --no-print-directory clean)
		@ echo "\n$(_BOLDMAGENTA)CHECKER PROG : $(_RESET)"
		@ (cd checker_prog; make --no-print-directory clean)

fclean:
		@ echo "$(_BOLDMAGENTA)LIBTF : $(_RESET)"
		@ (cd libft; make --no-print-directory fclean)
		@ echo "\n$(_BOLDMAGENTA)CHECKER PROG : $(_RESET)"
		@ (cd checker_prog; make --no-print-directory fclean)

re:
		@ echo "$(_BOLDMAGENTA)LIBTF : $(_RESET)"
		@ (cd libft; make --no-print-directory re)
		@ echo "\n$(_BOLDMAGENTA)CHECKER PROG : $(_RESET)"
		@ (cd checker_prog; make --no-print-directory re)

.PHONY:	all clean fclean re
