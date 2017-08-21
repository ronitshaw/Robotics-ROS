#include "ros/ros.h"
#include "math_two_nums/MathTwoNums.h"
#include "math_two_nums/Mode.h"
#include "std_srvs/Empty.h"

using namespace math_two_nums;
int main(int argc, char **argv)
{
	ros::init(argc, argv, "math_two_nums_client");
	ros::NodeHandle node;

	// Setup the client for mathing two numbers.
	ros::ServiceClient mathClient =
	node.serviceClient<math_two_nums::MathTwoNums>("math_two_nums");

	ros::ServiceClient modeClient =
	node.serviceClient<math_two_nums::Mode>("set_math_mode");

	// Setup client to exit session.
	ros::ServiceClient exitClient = node.serviceClient<std_srvs::Empty>("exit");

	/***************************
	 *
	 * SETUP MODE CLIENT HERE.
	 *
	 ***************************/
	math_two_nums::MathTwoNums srv;
	math_two_nums::Mode mode_srv;

	std::string mode = "ADDITION";

	while(ros::ok())
	{
		std::string input;

		// Clear screen.
		std::cout << "\033[2J\033[1;1H";

		// Print menu.
		std::cout << "MAIN MENU" << std::endl;
		std::cout << "---------------------------------" << std::endl;
		std::cout << "Current mode: " << mode << std::endl;
		std::cout << "Options:" << std::endl;
		std::cout << "  N - Enter numbers" << std::endl;
		std::cout << "  M - Enter mode" << std::endl;
		std::cout << "  E - Exit" << std::endl;
		std::cout << "---------------------------------" << std::endl;
		std::cout << "Choice: ";
		std::cin >> input;
		std::cout << std::endl;

		if (input == "N" || input == "n")
		{
			// Handle the enter numbers choice.

			// Clear screen.
			std::cout << "\033[2J\033[1;1H";

			// Print number menu.
			std::cout << "ENTER NUMBERS" << std::endl;
			std::cout << "---------------------------------" << std::endl;
			std::cout << "Current mode: " << mode << std::endl;
			std::cout << "---------------------------------" << std::endl;

			// Get the first number.
			std::cout << "Enter first number: ";
			std::cin >> input;
			std::cout << std::endl;

			// Convert first number to a float.
			float first;
			try
			{
				first = std::stof(input);
			}
			catch (...)
			{
				std::cout << "'" << input << "'  is not a number" << std::endl;
				std::cout << "---------------------------------" << std::endl;

				// Continue message.
				std::cout << "Press any key to continue.";
				getchar();
				getchar();
				continue;
			}

			// Get the second number.
			std::cout << "Enter second number: ";
			std::cin >> input;
			std::cout << std::endl;

			// Convert second number to a float.
			float second;
			try
			{
				second = std::stof(input);
			}
			catch (...)
			{
				std::cout << "'" << input << "'  is not a number" << std::endl;
				std::cout << "---------------------------------" << std::endl;

				// Continue message.
				std::cout << "Press any key to continue.";
				getchar();
				getchar();
				continue;
			}

			srv.request.a = first;
			srv.request.b = second;

			// Call the service request.
			if (mathClient.call(srv))
			{
				if(srv.response.error.compare("SUCCESS") == 0)
				{
					std::cout << "Result: " << srv.response.result << std::endl;
				}
				else
				{
					std::cout << "Error Rx: "<< srv.response.error << std::endl;
				}
			}
			else
			{
				std::cout << "Failed to call service math_two_nums";
				return 1;
			}

			std::cout << "---------------------------------" << std::endl;

			// Continue message.
			std::cout << "Press any key to continue.";
			getchar();
			getchar();
			continue;
		}
		else if (input == "M" || input == "m")
		{
			// Handle the enter mode choice.

			// Clear screen.
			std::cout << "\033[2J\033[1;1H";

			// Print mode menu.
			std::cout << "MAIN MENU" << std::endl;
			std::cout << "---------------------------------" << std::endl;
			std::cout << "Current mode: " << mode << std::endl;
			std::cout << "Options:" << std::endl;
			std::cout << "  A - Addition" << std::endl;
			std::cout << "  S - Subtraction" << std::endl;
			std::cout << "  M - Multiplication" << std::endl;
			std::cout << "  D - Division" << std::endl;
			std::cout << "  E - Exit" << std::endl;
			std::cout << "---------------------------------" << std::endl;
			std::cout << "Enter mode: ";
			std::cin >> input;
			std::cout << std::endl;

			// Check if the mode is valid.
			if (input == "A" || input == "a")
			{
				mode == "ADDITION";
				mode_srv.request.mode=mode_srv.request.ADDITION;
			}
			else if (input == "S" || input == "s")
			{
				mode = "SUBTRACTION";
				mode_srv.request.mode=mode_srv.request.SUBTRACTION;
			}
			else if (input == "M" || input == "m")
			{
				mode = "MULTIPLICATION";
				mode_srv.request.mode=mode_srv.request.MULTIPLICATION;
			}
			else if (input == "D" || input == "d")
			{
				mode = "DIVISION";
				mode_srv.request.mode=mode_srv.request.DIVISION;
			}
			else if (input == "E" || input == "e")
			{
				std::cout << "Exiting..." << std::endl;

				// Call exit service.
				std_srvs::Empty exitSrv;
				exitClient.call(exitSrv);

				return 0;
			}
			else
			{
				std::cout << "'" << input << "' is not a valid mode." << std:: endl;
				std::cout << "---------------------------------" << std::endl;
				// Continue message.
				std::cout << "Press any key to continue.";
				getchar();
				getchar();
				continue;
			}

			/********************************
			 *
			 * HANDLE SETTING THE MODE HERE.
			 *
			 ********************************/
			if(mode.compare("ADDITION") == 0)
			{
				mode_srv.request.mode = mode_srv.request.ADDITION;
			}
			if(mode.compare("SUBTRACTION") == 0)
			{
				mode_srv.request.mode = mode_srv.request.SUBTRACTION;
			}
			if(mode.compare("MULTIPLICATION") == 0)
			{
				mode_srv.request.mode = mode_srv.request.MULTIPLICATION;
			}
			if(mode.compare("DIVISION") == 0)
			{
				mode_srv.request.mode = mode_srv.request.DIVISION;
			}
			if(modeClient.call(mode_srv) == true)
			{
				if(mode_srv.response.result)
				{
					std::cout << "Mode set to " << mode << std::endl;
					std::cout << "---------------------------------" << std::endl;
				}
				else
				{
					std::cout << "Mode Change Failed" << std::endl;
					return 1;
				}
			}
			else
			{
				std::cout << "Failed to call mode service " << std::endl;
				return 1;
			}
			// Continue message.
			std::cout << "Press any key to continue.";
			getchar();
			getchar();
			continue;
		}
		else if (input == "E" || input == "e")
		{
			std::cout << "Exiting..." << std::endl;

			// Call exit service.
			std_srvs::Empty exitSrv;
			exitClient.call(exitSrv);

			return 0;
		}
		else
		{
			std::cout << "'" << input << "' is not a valid choice." << std:: endl;
			std::cout << "---------------------------------" << std::endl;

			// Continue message.
			std::cout << "Press any key to continue.";
			getchar();
			getchar();
			continue;
		}
	}

	return 0;
}
