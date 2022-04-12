#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145, 137), _target("noname")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

bool	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::string temp;
	try
	{
		if (this->checkSignature(executor) == true)
		{
			temp = _target + "_shrubbery";
			std::ofstream file(temp.c_str());
			if (file.is_open())
			{
				file << "              _{\\ _{\\{\\/}/}/}_" << std::endl
             		 << "             {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl
					 << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl
					 << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl
					 << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << std::endl
					 << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl
					 << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl
					 << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl
					 << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl
					 << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl
					 << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl
					 << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl
					 << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl
					 << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl
					 << "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl
					 << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl
					 << "             {/{\\{\\{\\/}/}{\\{\\\\}/}" << std::endl
					 << "              {){/ {\\/}{\\/} \\}\\}" << std::endl
					 << "                   \\.-'.-/" << std::endl
					 << "          __...--- |'-.-'| --...__" << std::endl
					 << "   _...--    .-'   |'-.-'|  ' -.   --..__ " << std::endl
					 << " -     ' .  . '    |.'-._| '  . .  '  "    << std::endl
					 << " .  '-  '    .--'  | '-.'|    .  '  . '" << std::endl
					 << "          ' ..     |'-_.-|" << std::endl
					 << "  .  '  .       _.-|-._ -|-._  .  '  ." << std::endl
					 << "               .'   |'- .-|   '." << std::endl
					 << "  ..-'   ' .  '.   |-._.-|   .'  '  - ." << std::endl
					 << "   .-' '        '-._______.-'     '  ." << std::endl;
				file.close();
				return (true);
			}
		}
	}
	catch(const Form::cannotSigned &e)
	{
		std::cerr << e.what() << '\n';
		return (false);
	}
	return (true);
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		this->_target = other._target;
	return (*this);
}
