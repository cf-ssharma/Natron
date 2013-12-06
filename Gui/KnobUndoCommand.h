//  Natron
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef NATRON_GUI_KNOBUNDOCOMMAND_H_
#define NATRON_GUI_KNOBUNDOCOMMAND_H_

#include <map>
#include <QUndoCommand>

#include "Engine/Variant.h"

class KnobGui;

//================================================================


class KnobMultipleUndosCommand : public QUndoCommand
{
public:
    KnobMultipleUndosCommand(KnobGui *knob, const std::map<int, Variant> &oldValue, const std::map<int, Variant> &newValue, QUndoCommand *parent = 0);

    virtual void undo();

    virtual void redo();

private:
    // TODO: PIMPL
    std::map<int, Variant> _oldValue;
    std::map<int, Variant> _newValue;
    KnobGui *_knob;
};

class KnobUndoCommand : public QUndoCommand
{
public:
    KnobUndoCommand(KnobGui *knob, int dimension, const Variant &oldValue, const Variant &newValue, QUndoCommand *parent = 0);

    virtual void undo();

    virtual void redo();

    virtual int id() const;

    virtual bool mergeWith(const QUndoCommand *command);

private:
    // TODO: PIMPL
    int _dimension;
    Variant _oldValue;
    Variant _newValue;
    KnobGui *_knob;
};

#endif // NATRON_GUI_KNOBUNDOCOMMAND_H_
