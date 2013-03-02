package com.dao;

import java.util.ArrayList;
import java.util.List;

import org.hibernate.HibernateException;
import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.Transaction;

import com.domain.CategoryDomain;
import com.domain.FeedDomain;
import com.domain.UserDomain;
import com.entity.CategoryEntity;
import com.entity.FeedEntity;
import com.entity.UserEntity;

public class FeedDao {

	public FeedEntity getFeedEntity(FeedDomain feedDomain) {

		FeedEntity feedEntity = new FeedEntity();
		feedEntity.setFeedId(feedDomain.getFeedId());
		feedEntity.setUserName(feedDomain.getUserName());
		feedEntity.setFeed(feedDomain.getFeed());
		List<CategoryDomain> categoryDomainList = feedDomain
				.getCategoryDomainList();
		List<CategoryEntity> categoryEntityList = new ArrayList<CategoryEntity>();
		for (CategoryDomain categoryDomain : categoryDomainList) {
			CategoryEntity categoryEntity = new CategoryEntity();
			categoryEntity.setCategoryId(categoryDomain.getCategoryId());
			categoryEntityList.add(categoryEntity);
		}
		feedEntity.setCategoryEntityList(categoryEntityList);

		return feedEntity;
	}

	public FeedDomain getFeedDomain(FeedEntity feedEntity) {

		FeedDomain feedDomain = new FeedDomain();
		feedDomain.setFeedId(feedEntity.getFeedId());
		feedDomain.setFeed(feedEntity.getFeed());
		feedDomain.setUserName(feedEntity.getUserName());
		CategoryDao categoryDao = new CategoryDao();
		List<CategoryDomain> categoryDomainList = new ArrayList<CategoryDomain>();
		for (CategoryEntity categoryEntity : feedEntity.getCategoryEntityList()) {
			CategoryDomain categoryDomain = categoryDao
					.getCategoryDomain(categoryEntity);
			categoryDomainList.add(categoryDomain);
		}
		feedDomain.setCategoryDomainList(categoryDomainList);
		return feedDomain;
	}

	public void addFeeds(List<FeedDomain> feedDomainList) throws Exception {

		Session session = HibernateUtil.getSessionFactory().getCurrentSession();
		Transaction transaction = null;

		try {
			transaction = session.beginTransaction();
			for (FeedDomain feedDomain : feedDomainList) {
				FeedEntity feedEntity = getFeedEntity(feedDomain);
				session.save(feedEntity);
			}
		} catch (Exception exception) {
			if (transaction != null)
				transaction.rollback();
			throw exception;
		} finally {
			transaction.commit();
			// session.close();
		}

	}

	public void deleteFeeds(List<FeedDomain> feedDomainList) {

		Session session = HibernateUtil.getSessionFactory().getCurrentSession();
		Transaction transaction = null;

		try {
			transaction = session.beginTransaction();
			for (FeedDomain feedDomain : feedDomainList) {
				FeedEntity feedEntity = getFeedEntity(feedDomain);
				session.delete(feedEntity);
			}
		} catch (HibernateException e) {
			if (transaction != null)
				transaction.rollback();
			e.printStackTrace();
		} finally {
			transaction.commit();
			// session.close();
		}

	}

	public void deleteFeed(FeedDomain feedDomain) {

		Session session = HibernateUtil.getSessionFactory().getCurrentSession();
		Transaction transaction = null;

		try {
			transaction = session.beginTransaction();

			FeedEntity feedEntity = getFeedEntity(feedDomain);
			session.delete(feedEntity);

		} catch (HibernateException e) {
			if (transaction != null)
				transaction.rollback();
			e.printStackTrace();
		} finally {
			transaction.commit();
			// session.close();
		}

	}

	public List<FeedDomain> getFeedsByCategories(
			List<CategoryDomain> categoryDomainList) {

		Session session = HibernateUtil.getSessionFactory().getCurrentSession();
		Transaction transaction = null;
		List<FeedDomain> feedDomainList = new ArrayList<FeedDomain>();
		try {
			transaction = session.beginTransaction();
			String hql = new String();
			for (CategoryDomain categoryDomain : categoryDomainList) {
				hql = "select f from " + CategoryEntity.class.getName() + " c "
						+ "join c.feedEntityList f "
						+ "where c.categoryId = :categoryId";
				Query query = session.createQuery(hql);
				query.setParameter("categoryId", categoryDomain.getCategoryId());
				@SuppressWarnings("unchecked")
				List<FeedEntity> feedEntityList = query.list();
				for (FeedEntity feedEntity : feedEntityList) {
					feedDomainList.add(getFeedDomain(feedEntity));
				}

			}
			return feedDomainList;
		} catch (HibernateException e) {
			if (transaction != null)
				transaction.rollback();
			e.printStackTrace();
		} finally {
			transaction.commit();
			// session.close();
		}
		return feedDomainList;
	}

	public List<FeedDomain> getFeedsByUser(UserDomain userDomain) {

		Session session = HibernateUtil.getSessionFactory().getCurrentSession();
		Transaction transaction = null;
		List<FeedDomain> feedDomainList = new ArrayList<FeedDomain>();
		try {
			transaction = session.beginTransaction();
			UserDao userDao = new UserDao();
			UserEntity userEntity = userDao.getUserEntity(userDomain);
			@SuppressWarnings("unchecked")
			List<FeedEntity> feedEntityList = session
					.createQuery(
							"select f from " + FeedEntity.class.getName()
									+ " f where f.UserEntity=?")
					.setParameter(0, userEntity).list();
			for (FeedEntity feedEntity : feedEntityList) {
				feedDomainList.add(getFeedDomain(feedEntity));
			}

			return feedDomainList;
		} catch (HibernateException e) {
			if (transaction != null)
				transaction.rollback();
			e.printStackTrace();
		} finally {
			transaction.commit();
			// session.close();
		}
		return feedDomainList;
	}

	public List<FeedDomain> getAllFeeds() {

		Session session = HibernateUtil.getSessionFactory().getCurrentSession();
		Transaction transaction = null;
		List<FeedDomain> feedDomainList = new ArrayList<FeedDomain>();
		try {
			transaction = session.beginTransaction();
			@SuppressWarnings("unchecked")
			List<FeedEntity> feedEntityList = session.createQuery(
					"select f from " + FeedEntity.class.getName() + " f")
					.list();
			for (FeedEntity feedEntity : feedEntityList) {
				feedDomainList.add(getFeedDomain(feedEntity));
			}

			return feedDomainList;
		} catch (HibernateException e) {
			if (transaction != null)
				transaction.rollback();
			e.printStackTrace();
		} finally {
			transaction.commit();
			// session.close();
		}
		return feedDomainList;
	}

	public FeedDomain getFeedsById(long feedId) {

		Session session = HibernateUtil.getSessionFactory().getCurrentSession();
		Transaction transaction = null;
		List<FeedDomain> feedDomainList = new ArrayList<FeedDomain>();
		try {
			transaction = session.beginTransaction();
			@SuppressWarnings("unchecked")
			List<FeedEntity> feedEntityList = session
					.createQuery(
							"select f from " + FeedEntity.class.getName()
									+ " f where f.feedId=?")
					.setParameter(0, feedId).list();
			for (FeedEntity feedEntity : feedEntityList) {
				feedDomainList.add(getFeedDomain(feedEntity));
			}

			return feedDomainList.get(0);
		} catch (HibernateException e) {
			if (transaction != null)
				transaction.rollback();
			e.printStackTrace();
		} finally {
			transaction.commit();
			// session.close();
		}
		return new FeedDomain();
	}

}
