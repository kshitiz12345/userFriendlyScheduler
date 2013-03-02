package com.service;

import com.dao.UserDao;
import com.domain.UserDomain;

public class UserService {

	public void addUser(UserDomain userDomain) throws Exception {
		try {
			UserDao userDao = new UserDao();
			if (userDomain.getName() == null)
				userDomain.setName("Anonymous");
			userDomain.setNumberOfFeedsUsed(0);
			userDao.addUser(userDomain);
		} catch (Exception exception) {
			throw exception;
		}
	}

	public UserDomain getUserByEmailId(String emailId) throws Exception {
		try {
			UserDao userDao = new UserDao();
			return userDao.getUserByEmailId(emailId);
		} catch (Exception exception) {
			throw exception;
		}
	}

	public boolean checkUser(String emailId) throws Exception {
		try {
			UserDao userDao = new UserDao();
			return userDao.checkUser(emailId);
		} catch (Exception exception) {
			throw exception;
		}
	}

	public UserDomain getUserByUserId(long userId) throws Exception {
		try {
			UserDao userDao = new UserDao();
			return userDao.getUserByUserId(userId);
		} catch (Exception exception) {
			throw exception;
		}
	}

}
