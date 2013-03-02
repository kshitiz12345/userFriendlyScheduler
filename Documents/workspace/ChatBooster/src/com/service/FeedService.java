package com.service;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

import com.dao.EmailDao;
import com.dao.FeedDao;
import com.domain.CategoryDomain;
import com.domain.EmailDomain;
import com.domain.FeedDomain;

public class FeedService {

	public void sendFeedsToEmails(List<FeedDomain> feedDomainList)
			throws Exception {

		try {
			System.out.println("Called mail");
			EmailDao emailDao = new EmailDao();
			for (FeedDomain feedDomain : feedDomainList) {
				List<CategoryDomain> categoryDomainList = feedDomain
						.getCategoryDomainList();
				List<EmailDomain> emailDomainList = emailDao
						.getEmailByCategories(categoryDomainList);
				Set<String> emailSet = new HashSet<String>();

				for (EmailDomain emailDomain : emailDomainList) {
					emailSet.add(emailDomain.getEmailId());
				}
				for(String set : emailSet) {
					System.out.println("mail is " + set);
				}
				// deleteFeed(feedDomain);
			}

		} catch (Exception exception) {
			throw exception;
		}
	}

	public void addFeeds(List<FeedDomain> feedDomainList) throws Exception {
		try {
			FeedDao feedDao = new FeedDao();
			feedDao.addFeeds(feedDomainList);
		} catch (Exception exception) {
			throw exception;
		}
	}

	public List<FeedDomain> getFeedsByCategories(
			List<CategoryDomain> categoryDomainList) throws Exception {

		try {
			FeedDao feedDao = new FeedDao();
			return feedDao.getFeedsByCategories(categoryDomainList);
		} catch (Exception exception) {
			throw exception;
		}
	}

	public List<FeedDomain> getAllFeeds() throws Exception {

		try {
			FeedDao feedDao = new FeedDao();
			return feedDao.getAllFeeds();
		} catch (Exception exception) {
			throw exception;
		}
	}

	public void deleteFeeds(List<FeedDomain> feedDomainList) throws Exception {

		try {
			FeedDao feedDao = new FeedDao();
			feedDao.deleteFeeds(feedDomainList);
		} catch (Exception exception) {
			throw exception;
		}
	}

	public void deleteFeed(FeedDomain feedDomain) throws Exception {

		try {
			FeedDao feedDao = new FeedDao();
			feedDao.deleteFeed(feedDomain);
		} catch (Exception exception) {
			throw exception;
		}
	}

	public FeedDomain getFeedsById(long feedId) throws Exception {

		try {
			FeedDao feedDao = new FeedDao();
			return feedDao.getFeedsById(feedId);
		} catch (Exception exception) {
			throw exception;
		}
	}
}
