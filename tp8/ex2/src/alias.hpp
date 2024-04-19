#pragma once

<<<<<<< HEAD
#include "../lib/InstanceCounter.hpp";
#include <memory>

using PTR_ALIAS1 = std::unique_ptr<InstanceCounter>;

using PTR_ALIAS2 = InstanceCounter*;
=======
#include "../lib/InstanceCounter.hpp"
#include <memory>

#define PTR_ALIAS1 std::unique_ptr<InstanceCounter>
#define PTR_ALIAS2 InstanceCounter* 
>>>>>>> a1e5913736695fd61da28e7a78026db63a1f337e
