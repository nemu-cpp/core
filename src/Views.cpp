/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "Views.h"

namespace Nemu
{

Views::Views()
{
}

Views::Views(std::shared_ptr<TemplateEngine> engine)
    : m_engine(engine)
{
}

const TemplateEngine& Views::engine() const
{
    return *m_engine;
}

}
