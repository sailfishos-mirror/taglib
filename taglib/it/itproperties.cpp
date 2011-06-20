/***************************************************************************
    copyright           :(C) 2011 by Mathias Panzenböck
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

#include "itproperties.h"

using namespace TagLib;
using namespace IT;

class IT::Properties::PropertiesPrivate
{
public:
  PropertiesPrivate() :
    channels(0),
    tableLength(0),
    stereo(false),
    instrumentCount(0),
    sampleCount(0),
    patternCount(0),
    version(0),
    compatibleVersion(0),
    flags(0),
    special(0),
    globalVolume(0),
    mixVolume(0),
    tempo(0),
    bpmSpeed(0),
    panningSeparation(0),
    pitchWheelDepth(0)
  {
  }

  int    channels;
  ushort tableLength;
  bool   stereo;
  ushort instrumentCount;
  ushort sampleCount;
  ushort patternCount;
  ushort version;
  ushort compatibleVersion;
  ushort flags;
  ushort special;
  ushort globalVolume;
  ushort mixVolume;
  uchar  tempo;
  uchar  bpmSpeed;
  uchar  panningSeparation;
  uchar  pitchWheelDepth;
};

IT::Properties::Properties(AudioProperties::ReadStyle propertiesStyle) :
  AudioProperties(propertiesStyle),
  d(new PropertiesPrivate)
{
}

IT::Properties::~Properties()
{
  delete d;
}

int IT::Properties::length() const
{
  return 0;
}

int IT::Properties::bitrate() const
{
  return 0;
}

int IT::Properties::sampleRate() const
{
  return 0;
}

int IT::Properties::channels() const
{
  return d->channels;
}

ushort IT::Properties::tableLength() const
{
  return d->tableLength;
}

bool IT::Properties::stereo() const
{
  return d->stereo;
}

ushort IT::Properties::instrumentCount() const
{
  return d->instrumentCount;
}

ushort IT::Properties::sampleCount() const
{
  return d->sampleCount;
}

ushort IT::Properties::patternCount() const
{
  return d->patternCount;
}

ushort IT::Properties::version() const
{
  return d->version;
}

ushort IT::Properties::compatibleVersion() const
{
  return d->compatibleVersion;
}

ushort IT::Properties::flags() const
{
  return d->flags;
}

ushort IT::Properties::special() const
{
  return d->special;
}

ushort IT::Properties::globalVolume() const
{
  return d->globalVolume;
}

ushort IT::Properties::mixVolume() const
{
  return d->mixVolume;
}

uchar IT::Properties::tempo() const
{
  return d->tempo;
}

uchar IT::Properties::bpmSpeed() const
{
  return d->bpmSpeed;
}

uchar IT::Properties::panningSeparation() const
{
  return d->panningSeparation;
}

uchar IT::Properties::pitchWheelDepth() const
{
  return d->pitchWheelDepth;
}

void IT::Properties::setChannels(int channels)
{
  d->channels = channels;
}

void IT::Properties::setTableLength(ushort tableLength)
{
  d->tableLength = tableLength;
}

void IT::Properties::setStereo(bool stereo)
{
  d->stereo = stereo;
}

void IT::Properties::setInstrumentCount(ushort instrumentCount) {
  d->instrumentCount = instrumentCount;
}

void IT::Properties::setSampleCount(ushort sampleCount)
{
  d->sampleCount = sampleCount;
}

void IT::Properties::setPatternCount(ushort patternCount)
{
  d->patternCount = patternCount;
}

void IT::Properties::setFlags(ushort flags)
{
  d->flags = flags;
}

void IT::Properties::setSpecial(ushort special)
{
  d->special = special;
}

void IT::Properties::setCompatibleVersion(ushort compatibleVersion)
{
  d->compatibleVersion = compatibleVersion;
}

void IT::Properties::setVersion(ushort version)
{
  d->version = version;
}

void IT::Properties::setGlobalVolume(ushort globalVolume)
{
  d->globalVolume = globalVolume;
}

void IT::Properties::setMixVolume(ushort mixVolume)
{
  d->mixVolume = mixVolume;
}

void IT::Properties::setTempo(uchar tempo)
{
  d->tempo = tempo;
}

void IT::Properties::setBpmSpeed(uchar bpmSpeed)
{
  d->bpmSpeed = bpmSpeed;
}

void IT::Properties::setPanningSeparation(uchar panningSeparation)
{
  d->panningSeparation = panningSeparation;
}

void IT::Properties::setPitchWheelDepth(uchar pitchWheelDepth)
{
  d->pitchWheelDepth = pitchWheelDepth;
}
