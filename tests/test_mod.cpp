/***************************************************************************
    copyright           : (C) 2011 by Mathias Panzenböck
    email               : grosser.meister.morti@gmx.net
 ***************************************************************************/

/***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it  under the terms of the GNU Lesser General Public License version  *
 *   2.1 as published by the Free Software Foundation.                     *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful, but   *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,            *
 *   MA  02110-1301  USA                                                   *
 ***************************************************************************/

#include <cppunit/extensions/HelperMacros.h>
#include <modfile.h>
#include "utils.h"

using namespace std;
using namespace TagLib;

static const String titleBefore("title of song");
static const String titleAfter("changed title");

static const String commentBefore(
  "Instrument names\n"
  "are abused as\n"
  "comments in\n"
  "module file formats.\n"
  "-+-+-+-+-+-+-+-+-+-+-+\n"
  "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

static const String newComment(
  "This line will be truncated because it is too long for a mod instrument name.\n"
  "This line is ok.");

static const String commentAfter(
  "This line will be trun\n"
  "This line is ok.\n"
  "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

class TestMod : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE(TestMod);
  CPPUNIT_TEST(testReadTags);
  CPPUNIT_TEST(testWriteTags);
  CPPUNIT_TEST_SUITE_END();

public:
  void testReadTags()
  {
    testRead(TEST_FILE_PATH_C("test.mod"), titleBefore, commentBefore);
  }

  void testWriteTags()
  {
    ScopedFileCopy copy("test", ".mod");
    {
      Mod::File file(copy.fileName().c_str());
      CPPUNIT_ASSERT(file.tag() != 0);
      file.tag()->setTitle(titleAfter);
      file.tag()->setComment(newComment);
      CPPUNIT_ASSERT(file.save());
    }
    testRead(copy.fileName().c_str(), titleAfter, commentAfter);
    CPPUNIT_ASSERT(fileEqual(
      copy.fileName(),
      TEST_FILE_PATH_C("changed.mod")));
  }

private:
  void testRead(FileName fileName, const String &title, const String &comment)
  {
    Mod::File file(fileName);

    CPPUNIT_ASSERT(file.isValid());

    Mod::Properties *p = file.audioProperties();
    Mod::Tag *t = file.tag();
    
    CPPUNIT_ASSERT(0 != p);
    CPPUNIT_ASSERT(0 != t);

    CPPUNIT_ASSERT_EQUAL(0, p->length());
    CPPUNIT_ASSERT_EQUAL(0, p->bitrate());
    CPPUNIT_ASSERT_EQUAL(0, p->sampleRate());
    CPPUNIT_ASSERT_EQUAL(8, p->channels());
    CPPUNIT_ASSERT_EQUAL(31U, p->instrumentCount());
    CPPUNIT_ASSERT_EQUAL((uchar)1, p->tableLength());
    CPPUNIT_ASSERT_EQUAL(title, t->title());
    CPPUNIT_ASSERT_EQUAL(String::null, t->artist());
    CPPUNIT_ASSERT_EQUAL(String::null, t->album());
    CPPUNIT_ASSERT_EQUAL(comment, t->comment());
    CPPUNIT_ASSERT_EQUAL(String::null, t->genre());
    CPPUNIT_ASSERT_EQUAL(0U, t->year());
    CPPUNIT_ASSERT_EQUAL(0U, t->track());
    CPPUNIT_ASSERT_EQUAL(String("StarTrekker"), t->trackerName());
  }
};

CPPUNIT_TEST_SUITE_REGISTRATION(TestMod);
