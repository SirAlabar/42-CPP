#==============================================================================#
#                                   COLORS                                       #
#==============================================================================#

RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENTA		= \033[0;35m
CYAN		= \033[0;36m
WHITE		= \033[0;37m
GRAY        = \033[1;30m
RESET		= \033[0m

#==============================================================================#
#                                   TARGETS                                      #
#==============================================================================#

NAME		= violence
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS		= $(SRCS:.cpp=.o)

#==============================================================================#
#                                   RULES                                        #
#==============================================================================#

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo
			@echo
			@echo "                $(WHITE).7$(RESET)"
			@echo "              $(WHITE).'/$(RESET)"
			@echo "             $(WHITE)/ /$(RESET)"
			@echo "            $(WHITE)/ /$(RESET)"
			@echo "           $(WHITE)/ /$(RESET)"
			@echo "          $(WHITE)/ /$(RESET)"
			@echo "         $(WHITE)/ /$(RESET)"
			@echo "        $(WHITE)/ /$(RESET)"
			@echo "       $(WHITE)/ /$(RESET)"
			@echo "      $(WHITE)/ /$(RESET)"
			@echo "     $(WHITE)/_/$(RESET)"
			@echo "  $(WHITE),-\\__\\"
			@echo "  $(WHITE)|f-\"Y\\|$(RESET)"
			@echo "  $(WHITE)\\()7L/$(RESET)"
			@echo "   $(WHITE)cgD                            __ _"
			@echo "   $(WHITE)|\\(                        .'  Y '>,"
			@echo "    $(WHITE)\\ \\                      / $(RED)_   _$(RESET)   \\"
			@echo "     $(WHITE)\\ \\                     )$(RED)(_) (_)$(RESET)(|}"
			@echo "      $(WHITE)\\ \\                   {  4A   } /"
			@echo "       $(WHITE)\\ \\                   \\uLuJJ/\\l"
			@echo "        $(WHITE)\\ \\                  |3    p)/"
			@echo "         $(WHITE)\\ \\ __________$(RESET)      /nnm_n//"
			@echo "         $(WHITE)c7___-__,__-)\\,__)(\".$(RESET)  \\_>-<_/D"
			@echo "                   $(WHITE)//V $(RESET)\\_\"-._.__G G_c__.-__<\"/ ( \\"
			@echo "                          <\"-._>__-,G_.___)\\   \\7\\"
			@echo "                         (\"-.__.|\"<.__.-\" )    \\ \\"
			@echo "                         |\"-.__\"\\  |\"-.__.-\".\\  \\ \\"
			@echo "                         (\"-.__\"\". \\-.__.-\".|    \\_\\"
			@echo "                         \\\"-.__\"\"|!|\"-.__.-\".)    \\ \\"
			@echo "                          \"-.__\"\"\\_|\"-.__.-\"./     \\ l"
			@echo "                           \".__\"\"\"\\G>-.__.-\">       .--,_"
			@echo
			@echo "$(BLUE)Compiling...$(RESET)"
			@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
			@echo "$(GREEN)Compilation successful! $(NAME) is ready.$(RESET)"

clean:
			@echo "$(YELLOW)Cleaning object files...$(RESET)"
			@rm -f $(OBJS)
			@echo "$(GREEN)Clean done!$(RESET)"

fclean:		clean
			@echo "$(YELLOW)Cleaning executable...$(RESET)"
			@rm -f $(NAME)
			@echo "$(GREEN)Full clean done!$(RESET)"

%.o: 		%.cpp
			@$(CXX) $(CXXFLAGS) -c $< -o $@

re:			fclean all

.PHONY:		all clean fclean re