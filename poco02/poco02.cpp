#include "poco02.h"

#include "Poco/Data/Session.h"
#include "Poco/Data/PostgreSQL/Connector.h"
#include <vector>
#include <iostream>

using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;


int main(int argc, char** argv) {

    Poco::Data::PostgreSQL::Connector::registerConnector();

/*
    // create a session
    Session session("SQLite", "sample.db");

    // drop sample table, if it exists
    session << "DROP TABLE IF EXISTS Person", now;

    // (re)create table
    session << "CREATE TABLE Person (Name VARCHAR(30), Address VARCHAR, Age INTEGER(3))", now;

    // insert some rows
    Person person =
            {
                    "Bart Simpson",
                    "Springfield",
                    12
            };

    Statement insert(session);
    insert << "INSERT INTO Person VALUES(?, ?, ?)",
            use(person.name),
            use(person.address),
            use(person.age);

    insert.execute();

    person.name    = "Lisa Simpson";
    person.address = "Springfield";
    person.age     = 10;

    insert.execute();

    // a simple query
    Statement select(session);
    select << "SELECT Name, Address, Age FROM Person",
            into(person.name),
            into(person.address),
            into(person.age),
            range(0, 1); //  iterate over result set one row at a time

    while (!select.done())
    {
        select.execute();
        std::cout << person.name << " " << person.address << " " << person.age << std::endl;
    }

    // another query - store the result in a container
    std::vector<std::string> names;
    session << "SELECT Name FROM Person",
            into(names),
            now;

    for (std::vector<std::string>::const_iterator it = names.begin(); it != names.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
*/
    return 0;

}