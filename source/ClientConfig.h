/*
 * ClientConfig.h
 *
 *  Created on: 28 Jul 2013
 *      Author: Patrick
 */

#include <forms.hpp>

#include <string>
#include <ostream>

#ifndef CLIENTCONFIG_H_
#define CLIENTCONFIG_H_

namespace WinampRemote
{
namespace Config
{

/**
 * class to wrap up the client configuration
 */
class ClientConfig
{
private:

	TPoint m_CommandsPos;
	bool m_CommandsVisible;
	TPoint m_VolumePos;
	bool m_VolumeVisible;
	TRect m_PlaylistPos;
	bool m_PlaylistVisible;
	std::string m_endpoint;
	std::string m_address;
	bool m_autohide;
	bool m_autorestore;
	bool m_updatePerSong;
	bool m_visible;
	int m_pollInterval;

public:
	/**
	 * constructor - default initialises
	 */
	ClientConfig():
		m_CommandsPos(Point(0, 0)), m_CommandsVisible(false),
		m_VolumePos(Point(0,0)), m_VolumeVisible(false),
		m_PlaylistPos(Rect(0,0,0,0)), m_PlaylistVisible(), m_endpoint(""), m_address(""),
		m_autohide(false), m_autorestore(false),m_updatePerSong(false),
		m_visible(true), m_pollInterval(10) {}
	/**
	 * reads the configuration from the registry
	 */
	void read();
	/**
	 * writes the configuration to the registry, taking bounds directly from the forms
	 * @param frmCommands
	 * @param frmPlaylist
	 * @param frmSettings
	 */
	void write(const TForm * const frmCommands,
			   const TForm * const frmPlaylist,
			   const TForm * const frmSettings) const;

	/**
	 * returns a modifiable record for the top left position of the toolbar
	 * @return TPoint for position
	 */
	TPoint& CommandsPos() { return m_CommandsPos; }

	/**
	 * returns a modifiable record for the top left position of the volume form
	 * @return TPoint for position
	 */
	TPoint& VolumePos() { return m_VolumePos; }

	/**
	 * returns a modifiable value for the visibility of the toolbar
	 * @return visible value
	 */
	bool& CommandsVisible() { return m_CommandsVisible; }

	/**
	 * returns a modifiable value for the visibility of the volume form
	 * @return visible value
	 */
	bool& VolumeVisible() { return m_VolumeVisible; }

	/**
	 * returns a modifiable record for the bounds rect position of the playlist form
	 * @return TRect for bound
	 */
	TRect& PlaylistPos() { return m_PlaylistPos; }

	/**
	 * returns a modifiable value for the visibility of the playlist
	 * @return visible value
	 */
	bool& PlaylistVisible() { return m_PlaylistVisible; }

	/**
	 * returns a modifiable value for the autorestore value
	 * @return auto restore value
	 */
	bool& AutoRestore() { return m_autorestore; }

	/**
	 * streams out a representation of of the class to the ostream
	 * @param os - ostream instance
	 * @return os - ostream instance
	 */
	std::ostream& streamOut(std::ostream& os) const
	{

		os <<
		"Command Pos [" << m_CommandsPos.x << "," << m_CommandsPos.y << "]" <<
		"Commands Visible [" << m_CommandsVisible << "]" <<
		"Volume Pos [" << m_VolumePos.x << "," << m_VolumePos.y << "]" <<
		"Volume Visible [" << m_VolumeVisible << "]" <<
		"Playlist Pos [" << m_PlaylistPos.Top << "," << m_PlaylistPos.Left <<
					  "," << m_PlaylistPos.Bottom << "," << m_PlaylistPos.Right << "]" <<
		"Playlist Visible [" << m_PlaylistVisible << "]" <<
		"Endpoint [" << m_endpoint << "]" <<
		"Address [" << m_address << "]" <<
		"Auto Restore [" << m_autorestore << "]" <<
		"Auto Hide [" << m_autohide << "]" <<
		"Update per Song [" << m_updatePerSong << "]" <<
		"Visible [" << m_visible << "]" <<
		"Poll Interval [" << m_pollInterval << "]"
		;

		return os;
	}

	/**
	 * operator overload to allow streaming to the ostream
	 * @param os - ostream instance
	 * @param config - class instance
	 * @return os - ostream instance
	 */

}; // ClientConfig

std::ostream& operator << (std::ostream& os, const ClientConfig & config)
{
	return config.streamOut(os);
}

} /* namespace Config */
} /* namespace WinampRemote */
#endif /* CLIENTCONFIG_H_ */
