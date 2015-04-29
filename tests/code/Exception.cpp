#define BOOST_TEST_MODULE Message
#include <boost/test/unit_test.hpp>

#include <ostream>

#include <dcmtk/config/osconfig.h>
#include <dcmtk/ofstd/ofcond.h>
#include <dcmtk/dcmdata/dcuid.h>

#include "dcmtkpp/Exception.h"

namespace dcmtkpp
{

std::ostream & operator<<(std::ostream & stream, Exception::Source const & type)
{
    stream << int(type);
    return stream;
}

}

BOOST_AUTO_TEST_CASE(StringConstructor)
{
    dcmtkpp::Exception const exception("foo");
    BOOST_CHECK_EQUAL(exception.get_source(), dcmtkpp::Exception::Source::Message);
    BOOST_CHECK_EQUAL(exception.what(), "foo");
    BOOST_CHECK_THROW(exception.get_condition(), dcmtkpp::Exception);
}

BOOST_AUTO_TEST_CASE(ConditionConstructor)
{
    dcmtkpp::Exception const exception(EC_IllegalParameter);
    BOOST_CHECK_EQUAL(exception.get_source(), dcmtkpp::Exception::Source::Condition);
#if OFFIS_DCMTK_VERSION_NUMBER < 361
    BOOST_CHECK_EQUAL(exception.what(), EC_IllegalParameter.text());
#else
    BOOST_CHECK_EQUAL(exception.what(), EC_IllegalParameter.theText);
#endif
    BOOST_CHECK(exception.get_condition() == EC_IllegalParameter);
}
