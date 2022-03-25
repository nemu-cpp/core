/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "Web/RequestHandlers/FileSystemWebRequestHandler.hpp"

using namespace boost::filesystem;
using namespace Ishiko;
using namespace std;

namespace Nemu
{

FileSystemWebRequestHandler::FileSystemWebRequestHandler(path root)
    : m_root(root)
{
    m_defaults.push_back("index.html");
}

void FileSystemWebRequestHandler::run(const WebRequest& request, WebResponseBuilder& response, Logger& logger)
{
    string path = request.URI();
    if (path == "/")
    {
        for (size_t i = 0; i < m_defaults.size(); ++i)
        {
            // TODO: handle multiple default paths correctly
            //string path = m_root / m_defaults[i];
            // TODO
            //session.response().sendFile(path);
        }
    }
}

}
