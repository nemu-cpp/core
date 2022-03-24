/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_VIEWS_H_
#define _NEMU_CPP_CORE_VIEWS_H_

#include "TemplateEngine.hpp"
#include <memory>

namespace Nemu
{

/// A list of templating engines and their associated settings.
class Views
{
public:
    Views();
    Views(std::shared_ptr<TemplatingEngine> engine);

    const TemplatingEngine& engine() const;

private:
    std::shared_ptr<TemplatingEngine> m_engine;
};

}

#endif
