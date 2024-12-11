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

NAME		= megaphone
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= megaphone.cpp
OBJS		= $(SRCS:.cpp=.o)

#==============================================================================#
#                                   RULES                                        #
#==============================================================================#

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo
			@echo
			@echo "               $(WHITE).7$(RESET)"
			@echo "             $(WHITE).'/$(RESET)"
			@echo "            $(WHITE)/ /$(RESET)"
			@echo "           $(WHITE)/ /$(RESET)"
			@echo "          $(WHITE)/ /$(RESET)"
			@echo "         $(WHITE)/ /$(RESET)"
			@echo "        $(WHITE)/ /$(RESET)"
			@echo "       $(WHITE)/ /$(RESET)"
			@echo "      $(WHITE)/ /$(RESET)"
			@echo "     $(WHITE)/ /$(RESET)"
			@echo "    $(GRAY)__|/$(RESET)"
			@echo "  $(GRAY),-\\__\\"
			@echo "  $(GRAY)|f-\"Y\\|$(RESET)"
			@echo "  $(GRAY)\\()7L/$(RESET)"
			@echo "   $(GRAY)cgD                            __ _"
			@echo "   $(GRAY)|\\(                        .'  Y '>,"
			@echo "    $(GRAY)\\ \\                      / $(RED)_   _$(RESET)   \\"
			@echo "     $(GRAY)\\ \\                     )$(RED)(_) (_)$(RESET)(|}"
			@echo "      $(GRAY)\\ \\                   {  4A   } /"
			@echo "       $(GRAY)\\ \\                   \\uLuJJ/\\l"
			@echo "        $(GRAY)\\ \\                  |3    p)/"
			@echo "         $(GRAY)\\ \\ __________$(RESET)      /nnm_n//"
			@echo "         $(GRAY)c7___-__,__-)\\,__)(\".$(RESET)  \\_>-<_/D"
			@echo "                   $(GRAY)//V $(RESET)\\_\"-._.__G G_c__.-__<\"/ ( \\"
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