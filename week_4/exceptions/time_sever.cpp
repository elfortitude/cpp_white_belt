/*
 * Используя функцию AskTimeServer, напишите класс TimeServer.
 *
 * Метод GetCurrentTime должен вести себя так:
 *
 * он должен вызвать функцию AskTimeServer, записать её результат в поле last_fetched_time
 * и вернуть значение этого поля;
 *
 * если AskTimeServer выбросила исключение system_error, метод GetCurrentTime должен его поймать
 * и вернуть текущее значение поля last_fetched_time. Таким образом мы скрываем от пользователя
 * сетевые проблемы, возвращая значение, которое было получено при последнем успешном обращении
 * к серверу;
 *
 * если AskTimeServer выбросила другое исключение, метод GetCurrentTime должен пробросить его дальше,
 * потому что в рамках класса TimeServer мы не знаем, как обрабатывать проблемы, не связанные
 * со сбоями сети.
*/

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class		TimeServer
{
public:
	string	GetCurrentTime()
	{
		try
		{
			last_fetched_time = AskTimeServer();
		}
		catch (system_error& se){
		}
		return last_fetched_time;
	}

private:
	string last_fetched_time = "00:00:00";
};
