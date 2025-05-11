#include "Authenticator.hpp"

int main()
{
  Authenticator auth;

  auth.registerUser("user1", "password1", false);
  auth.registerUser("admin1", "password1", true);
  auth.registerUser("user2", "password2", false);
  auth.registerUser("admin1", "password2", true);
  auth.registerUser("user3", "password3", false);
  auth.registerUser("admin3", "password3", true);
  auth.registerUser("user4", "password4", false);
    auth.registerUser("admin4", "password4", true);
    auth.registerUser("user5", "password5", false);
    auth.registerUser("admin5", "password5", true);
    auth.registerUser("user6", "password6", false);

  auth.login("user1", "password1");
  auth.accessResource();
  auth.logout();

  auth.login("admin1", "password1");
  auth.accessResource();
  auth.setResource("Ini adalah resource baru!");
  auth.accessResource();
  auth.logout();

  auth.login("user2", "password2");
  auth.accessResource();

  return 0;
}