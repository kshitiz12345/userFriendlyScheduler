package com.dao;

import java.util.List;

import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.Transaction;

import com.domain.UserDomain;
import com.entity.UserEntity;

public class UserDao {

	public UserEntity getUserEntity(UserDomain userDomain) {

		UserEntity userEntity = new UserEntity();

		userEntity.setEmailId(userDomain.getEmailId());
		userEntity.setName(userDomain.getName());
		userEntity.setUserId(userDomain.getUserId());
		userEntity.setNumberOfFeedsUsed(userDomain.getNumberOfFeedsUsed());

		return userEntity;
	}

	public UserDomain getUserDomain(UserEntity userEntity) {

		UserDomain userDomain = new UserDomain();

		userDomain.setEmailId(userEntity.getEmailId());
		userDomain.setName(userEntity.getName());
		userDomain.setNumberOfFeedsUsed(userEntity.getNumberOfFeedsUsed());
		userDomain.setUserId(userEntity.getUserId());

		return userDomain;
	}

	public void addUser(UserDomain userDomain) throws Exception {

		Session session = HibernateUtil.getSessionFactory().getCurrentSession();
		Transaction transaction = null;

		try {
			transaction = session.beginTransaction();
			UserEntity userEntity = getUserEntity(userDomain);
			session.save(userEntity);
		} catch (HibernateException e) {
			if (transaction != null)
				transaction.rollback();
			e.printStackTrace();
		} catch (Exception exception) {
			throw exception;
		} finally {
			transaction.commit();
			// session.close();
		}
	}

	public void updateUser(UserDomain userDomain) {

		Session session = HibernateUtil.getSessionFactory().getCurrentSession();
		Transaction transaction = null;

		try {
			transaction = session.beginTransaction();
			UserEntity userEntity = getUserEntity(userDomain);
			session.update(userEntity);
		} catch (HibernateException e) {
			if (transaction != null)
				transaction.rollback();
			e.printStackTrace();
		} finally {
			transaction.commit();
			// session.close();
		}

	}

	public UserDomain getUserByEmailId(String emailId) throws Exception {

		Session session = HibernateUtil.getSessionFactory().getCurrentSession();
		Transaction transaction = null;
		UserDomain userDomain = new UserDomain();
		try {
			transaction = session.beginTransaction();
			@SuppressWarnings("unchecked")
			List<UserEntity> userEntityList = (List<UserEntity>) session
					.createQuery(
							"select u from " + UserEntity.class.getName()
									+ " u where u.emailId=?")
					.setParameter(0, emailId).list();
			if (userEntityList.size() == 0)
				throw new Exception("No User Found");
			userDomain = getUserDomain(userEntityList.get(0));
			return userDomain;
		} catch (HibernateException e) {
			if (transaction != null)
				transaction.rollback();
			e.printStackTrace();
		} catch (Exception exception) {
			throw exception;
		} finally {
			// session.close();
			transaction.commit();
		}
		return userDomain;
	}

	public boolean checkUser(String emailId) throws Exception {

		Session session = HibernateUtil.getSessionFactory().getCurrentSession();
		Transaction transaction = null;
		try {
			transaction = session.beginTransaction();
			@SuppressWarnings("unchecked")
			List<UserEntity> userEntityList = (List<UserEntity>) session
					.createQuery(
							"select u from " + UserEntity.class.getName()
									+ " u where u.emailId=?")
					.setParameter(0, emailId).list();
			if (userEntityList.size() == 0)
				return false;
			else
				return true;
		} catch (HibernateException e) {
			if (transaction != null)
				transaction.rollback();
			e.printStackTrace();
		} catch (Exception exception) {
			throw exception;
		} finally {
			// session.close();
			transaction.commit();
		}
		return false;
	}

	public UserDomain getUserByUserId(long userId) {

		Session session = HibernateUtil.getSessionFactory().getCurrentSession();
		Transaction transaction = null;
		UserDomain userDomain = new UserDomain();
		try {
			transaction = session.beginTransaction();
			@SuppressWarnings("unchecked")
			List<UserEntity> userEntityList = session
					.createQuery(
							"select u from " + UserEntity.class.getName()
									+ " u where u.userId=?1")
					.setParameter(1, userId).list();
			userDomain = getUserDomain(userEntityList.get(0));
			return userDomain;
		} catch (HibernateException e) {
			if (transaction != null)
				transaction.rollback();
			e.printStackTrace();
		} finally {
			// session.close();
			transaction.commit();
		}
		return userDomain;
	}

}
