.. module:: NatronEngine
.. _Tracker:

Tracker
*******

Synopsis
--------

This class is a container for :doc:`tracks<NatronEngine.Track>`
See :ref:`detailed<tracker.details>` description below.

Functions
^^^^^^^^^

*    def :meth:`getAllTracks<NatronEngine.Tracker.getAllTracks>` ()
*    def :meth:`getSelectedTracks<NatronEngine.Tracker.getSelectedTracks>` ()
*    def :meth:`startTracking<NatronEngine.Tracker.startTracking>` (tracks, start, end, forward)
*    def :meth:`stopTracking<NatronEngine.Tracker.stopTracking>` ()

.. _tracker.details:

Detailed Description
--------------------

The Tracker is a special class attached to :doc:`effects<NatronEngine.Effect>` that needs
tracking capabilities. It contains all :doc:`tracks<NatronEngine.Track>` for this node
and also allow to start and stop tracking from a Python script.

Member functions description
^^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. method:: NatronEngine.Tracker.getAllTracks()

	:rtype: :class:`sequence`
	
	Returns all the tracks in this Tracker.

.. method:: NatronEngine.Tracker.getSelectedTracks()

	:rtype: :class:`sequence`
	
	Returns the user selected tracks
	
.. method:: NatronEngine.Tracker.startTracking> (tracks, start, end, forward)
	
	Start tracking the given *tracks* from *start* frame to *end* frame (*end* frame will
	not be tracked) in the direction given by *forward*.
	If *forward* is **False**, then *end* is expected to be lesser than *start*.
	
.. method::  NatronEngine.Tracker.stopTracking ()

	Stop any ongoing tracking for this Tracker.