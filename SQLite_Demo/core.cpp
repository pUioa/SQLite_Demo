#include <ctime>
#include <iostream>
#include <Windows.h>
#include "CppSQLite3.h"

#ifdef _WIN64
#pragma comment(lib, "lib/x64/SQLite3.lib")
#else
#pragma comment(lib, "lib/x86/SQLite3.lib")
#endif



using namespace std;



int main(int argc, char** argv)
{
	try
	{
	
		CppSQLite3DB db;

		db.open("Demo.db");		//不存在会自动创建

	

			//int type = 1; // 设置要插入的 Type 值
			//std::string value = "example@example.com"; // 设置要插入的 Value 值
			//std::string comment = "This email is blacklisted"; // 设置要插入的 Comment 值

			//std::string sql = "INSERT INTO BlackList (Type, Value, Comment) "
			//	"VALUES (?, ?, ?);";

			//CppSQLite3Statement stmt = db.compileStatement(sql.c_str());


			//stmt.bind(1, type);
			//stmt.bind(2, value.c_str());
			//stmt.bind(3, comment.c_str());

			//stmt.execDML(); // 执行 SQL 插入语句
		
		std::string sql = "SELECT * FROM BlackList;";
		CppSQLite3Query query = db.execQuery(sql.c_str());

		while (!query.eof()) {
			int type = query.getIntField("Type");
			std::string value = query.getStringField("Value");
			std::string comment = query.getStringField("Comment");

			// 打印查询结果
			std::cout << "Type: " << type << "	Value: " << value << "	Comment: " << comment << std::endl;
			
			query.nextRow();
		}

		system("pause");
		 sql = "UPDATE BlackList SET Value = 'pdfioac@qq.com' WHERE Type = 5;";
		db.execDML(sql.c_str());

	
		sql = "SELECT * FROM BlackList;";
		query = db.execQuery(sql.c_str());
		while (!query.eof()) {
			int type = query.getIntField("Type");
			std::string value = query.getStringField("Value");
			std::string comment = query.getStringField("Comment");

			// 打印查询结果
			std::cout << "Type: " << type << "	Value: " << value << "	Comment: " << comment << std::endl;

			query.nextRow();
		}

		std::cout << "邮箱修改成功！" << std::endl;

		
		query.finalize();
		db.close();
	}


	
	catch (CppSQLite3Exception& e)
	{
		cerr << e.errorCode() << ":" << e.errorMessage() << endl;
	}


}
