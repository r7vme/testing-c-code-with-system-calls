#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include <catch2/catch.hpp>
#include <fff/fff.h>
DEFINE_FFF_GLOBALS;

extern "C" {
// include our library header
#include "lib.h"

// define a fake function
FAKE_VALUE_FUNC(int, __wrap_get_nprocs_conf);
}

TEST_CASE("if more than one core then return true", "[is_multicore_system]")
{
  // always reset globally-defined fff objects
  // This is a limitation of pure-C fff, that it uses global objects.
  RESET_FAKE(__wrap_get_nprocs_conf);

  // if get_nprocs_conf will return 2
  __wrap_get_nprocs_conf_fake.return_val = 2;

  // then return true
  REQUIRE(is_multicore_system() == true);

  // also check that get_nprocs_conf was called once
  REQUIRE(__wrap_get_nprocs_conf_fake.call_count == 1);
}
