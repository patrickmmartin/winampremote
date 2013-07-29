/*
 * ClientConfig.cpp
 *
 *  Created on: 28 Jul 2013
 *      Author: Patrick
 */

#include <memory>
#include <registry.hpp>

#include "ClientConfig.h"

const char * sRegKey = "software\\PMMSoft\\Winamp controller\\client settings";
const char * sCommandsLeft = "Commands Left";
const char * sCommandsTop = "Commands Top";
const char * sCommandsVisible = "Commands Visible";
const char * sVolumeLeft = "Volume Left";
const char * sVolumeTop = "Volume Top";
const char * sVolumeVisible = "Volume Visible";
const char * sPlaylistLeft = "Playlist Left";
const char * sPlaylistTop = "Playlist Top";
const char * sPlaylistWidth = "Playlist Width";
const char * sPlaylistHeight = "Playlist Height";
const char * sPlaylistVisible = "Playlist Visible";

const char * sEndpoint = "Endpoint";
const char * sAddress = "Address";

const char * sEndPointDefault = "\\pipe\\winampremote";
const char * sAddressDefault = "localhost";

const char * sAutoHide = "AutoHide";
const char * sAutoRestore = "AutoRestore";

const char * sPlaylistUpdate = "Playlist Update";

const char * sVisible = "Visible";

const char * sPollInterval = "Poll Interval";

const char * sTrue = "true";
const char * sFalse = "false";

namespace WinampRemote
{
namespace Config
{


void ClientConfig::read()
{

	std::auto_ptr < TRegistry > reg(new TRegistry());

	reg->OpenKey(sRegKey, true);

    m_endpoint = reg->ReadString(sEndpoint).c_str();
    m_address = reg->ReadString(sAddress).c_str();

    if (m_endpoint == "")
      m_endpoint = sEndPointDefault;
    if (m_address == "")
      m_address = sAddressDefault;

     m_autohide =  !(reg->ReadString(sAutoHide).LowerCase() == sFalse);

     m_autorestore = !(reg->ReadString(sAutoRestore).LowerCase() == sFalse);


     if (reg->ReadString(sPlaylistUpdate).LowerCase() == "every song")
       m_updatePerSong = true;

     m_visible = (reg->ReadString("Visible").LowerCase() == sFalse);

     m_pollInterval = reg->ReadString("Poll Interval").ToIntDef(1);


}


void ClientConfig::write(const TForm * const frmCommands,
						 const TForm * const frmPlaylist,
						 const TForm * const frmSettings) const
{

	std::auto_ptr < TRegistry > reg(new TRegistry());

	reg->OpenKey(sRegKey, true);

	    if (m_endpoint != "")
	      reg->WriteString(sEndpoint, m_endpoint.c_str());
	    if (m_address != "")
	      reg->WriteString(sAddress, m_address.c_str());

	    reg->WriteString(sVisible, m_visible?sTrue:sFalse);

	    reg->WriteString("Poll Interval", AnsiString(m_pollInterval));
	    reg->WriteString("AutoHide", (m_autohide)?sTrue:sFalse);
	    reg->WriteString("AutoRestore", (m_autorestore)?sTrue:sFalse);

	     if  (m_updatePerSong)
	     {
	        reg->WriteString("Playlist Update", "every song");
	      }
	      else
	      {
	        reg->WriteString("Playlist Update", "playlist change");
	      }

	    // only save settings if check box checked, to prevent overwriting with defaults
	    if (m_autorestore){
	      reg->WriteString("Commands Left", AnsiString(frmCommands->Left));
	      reg->WriteString("Commands Top", AnsiString(frmCommands->Top));
	      reg->WriteString("Commands Visible", frmCommands->Visible?sTrue:sFalse);
	      reg->WriteString("Commands Docked", frmCommands->HostDockSite?sTrue:sFalse);

	      reg->WriteString("Playlist Left", AnsiString(frmPlaylist->Left));
	      reg->WriteString("Playlist Top", AnsiString(frmPlaylist->Top));
	      reg->WriteString("Playlist Width", AnsiString(frmPlaylist->Width));
	      reg->WriteString("Playlist Height", AnsiString(frmPlaylist->Height));
	      reg->WriteString("Playlist Visible", frmPlaylist->Visible?sTrue:sFalse);

	      reg->WriteString("Volume Left", AnsiString(frmSettings->Left));
	      reg->WriteString("Volume Top", AnsiString(frmSettings->Top));
	      reg->WriteString("Volume Visible", frmSettings->Visible?sTrue:sFalse);
	      }

}

} /* namespace Config */
} /* namespace WinampRemote */
