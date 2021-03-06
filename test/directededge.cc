#include "test.h"

#include "baldr/directededge.h"

using namespace std;
using namespace valhalla::baldr;

// Expected size is 40 bytes. Since there are still "spare" bits
// we want to alert if somehow any change grows this structure size
constexpr size_t kDirectedEdgeExpectedSize = 40;

namespace {

  void test_sizeof() {
    if (sizeof(DirectedEdge) != kDirectedEdgeExpectedSize)
      throw std::runtime_error("DirectedEdge size should be " +
                std::to_string(kDirectedEdgeExpectedSize) + " bytes" +
                " but is " + std::to_string(sizeof(DirectedEdge)));
  }

}

int main(void)
{
  test::suite suite("directededge");

  suite.test(TEST_CASE(test_sizeof));

  return suite.tear_down();
}
